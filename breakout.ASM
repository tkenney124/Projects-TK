	.model tiny
	.code
start:
	mov ax,1234h
	mov ax,cs
	mov ds,ax
	mov ax,0b800h
	mov es,ax

;--- YOUR CODE HERE ---
	cli ; ignore dos interrupts
	mov si,502
	add si,1
blockloop:	mov al,21h
	mov [es:si],al
	cmp si,580
	jl increment
increment:
	add si,4; to move column values
	cmp si,580
	jle blockloop

	
	mov si, paddx
	add si,3200
paddleloop:
	mov al,12h
	mov [es:si],al
	cmp  si,3286
	jle pincrement
pincrement:
	add si,2
	cmp si,3286
	jle paddleloop

	mov si, ballx ;create ball
	add si, bally
	mov al,55h
	mov [es:si], al
moveball:	mov bx, ballx
	mov dx, bally
	
	mov si, ballx ;
	add si, bally
	mov al, 0
	mov [es:si], al
	cmp dx,0 ; top of screen
	jg moveball2
	jmp changey
moveball2:	cmp bx, 0 ; left side
	jg moveball1
change:	jmp changex
moveball1:	cmp bx,139 ; right side
	jge change
	cmp dx, 3840 ; lose condition
	jl moveball3
	jmp loser1 ; end program
moveball3:	cmp balldy,0
	jge paddcheck
	jmp aftercheck
paddcheck:	cmp dx,3040 ; is at the top or on the paddle
	jge left
	jmp aftercheck
	
left:	
	cmp bx,paddx
	jl aftercheck
	
	add paddx,20 ; temp add to paddx
	cmp bx,paddx
	jle paddbounce
	jmp aftercheck
loser1:	jmp loser
paddbounce:
	sub paddx,20
	
	mov balldy,0ff60h ; make it go up again
	
	

	
aftercheck:	add bx, balldx
	add dx, balldy
	mov ballx,bx
	mov bally,dx
	mov al, 55h ; make ball visible again
	mov si, bx
	add si, dx
	mov [es:si], al
	mov cx, 3000h
delay:	sub cx, 1
	cmp cx,0
	jnz fix
	jmp moveball
fix:	in al,64h ; write to keyboard
	and al,1 ; read last digit
	jz delay ; goes back if no press
	in al,60h ; read from keyboard
	cmp al,4bh ; left arrow
	jz moveleft
	cmp al,4dh ; right arrow
	jz moveright
	jmp clrbuf ; clear the buffer
	
	jmp delay

loser:	jmp lose
changey:	mov ax,160
	mov balldy, ax; change to positive y aka down
	
	jmp aftercheck

changex:	mov ax,0
	sub ax,balldx ; -2 in 2s complement moves down
	mov balldx,ax ; negative balldx
	
	jmp aftercheck
moveleft:
	sub paddx,2
	mov al,12h
	mov si,paddx
	add si,3200
	mov [es:si],al
	add si,20
	mov al,0
	mov [es:si],al
	jmp clrbuf
moveright:
	mov al,0
	mov si,paddx
	add si,3200
	mov [es:si],al
	add si,20
	mov al,12h
	mov [es:si],al
	add paddx,2
	jmp clrbuf

clrbuf:	in al,60h
	in al,64h
	and al,1
	jnz clrbuf
	jmp delay

lose:	mov ah,0
	int 21h
	bally dw 1620 ; variable for ball y axis
	ballx dw 81;variable for ball x axis
	balldy dw 0ff60h ;variable for ball slope in y axis
	balldx dw 2 ; variable for ball x slope
	paddx dw 67 ; paddle slope - starts at 67 bytes in


	end
