.686
.model flat

.data

.code


_ArrayMult proc
	mov edi, dword ptr [esp + 8]
	mov esi, dword ptr [esp + 4]

	xor ecx, ecx
	forbegin1 :
	cmp ecx, dword ptr [esp + 12]
	je forend1
	mov ebx, dword ptr[edi] 
	add edi, 4				
	mov eax, dword ptr[esi] 
	add esi, 4				
	imul ebx
	mov ebx, dword ptr[esp + 16]

	add dword ptr [ebx + 0], eax
	add dword ptr [ebx + 4], edx
	adc dword ptr [ebx + 8], 0
	inc ecx
	jmp forbegin1
	forend1:
	ret
_ArrayMult endp


_CheckSum1 proc
	mov eax, dword ptr [esp + 4]
	mov ebx, dword ptr [esp + 8]
	adc eax, ebx
	mov ecx, dword ptr [esp + 12]

	mov ebx, dword ptr [esp + 16]
	mov ebx, 0
	jc _end_method1
	cmp eax, ecx
	jng _less_end1
	jmp _end_method1
	
	_less_end1:
	mov ebx, 1

	_end_method1:
	ret
_CheckSum1 endp


_CheckSum2 proc
	mov eax, dword ptr [esp + 4]
	mov ebx, dword ptr [esp + 8]
	adc eax, ebx
	mov ecx, dword ptr [esp + 12]

	mov ebx, dword ptr [esp + 16]
	mov ebx, 0
	jc _end_method2
	cmp eax, ecx
	jng _less_end2
	jmp _end_method2
	
	_less_end2:
	mov ebx, 1

	_end_method2:
	ret
_CheckSum2 endp


_CheckSum3 proc
	mov eax, dword ptr [esp + 4]
	mov ebx, dword ptr [esp + 8]
	adc eax, ebx
	mov ecx, dword ptr [esp + 12]

	mov ebx, dword ptr [esp + 16]
	mov ebx, 0
	jc _end_method3
	cmp eax, ecx
	jng _less_end3
	jmp _end_method3
	
	_less_end3:
	mov ebx, 1

	_end_method3:
	ret
_CheckSum3 endp

end
