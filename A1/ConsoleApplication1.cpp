#include <iostream>

using namespace std;

int main()
{
	int a, b, c, y;
	cin >> a >> b >> c >> y;
	// x = -(by + c) / 3a
	int remainder, divider, result;

	__asm {
		mov eax, b
		mov ebx, y
		imul ebx;			b* y
		mov ebx, c
		add ebx, eax;		b* y + c
		mov eax, 3
		imul a;				3 * a
		cmp eax, 0
		jg _a_is_greater_0
		neg eax
		neg ebx
		_a_is_greater_0 :
		mov divider, eax
		neg ebx;			-(b * y + c)
		mov esi, eax
		mov eax, ebx
		cdq
		idiv esi;			eax / esi
		mov result, eax
		mov remainder, edx

		cmp remainder, 0
		je _end
		jg _if_rem_greater0
		jl _if_rem_less0

		_if_rem_greater0 :
		mov eax, 2
		mul remainder
		cmp eax, divider
		jg _if_eax_greater_div1
		jl _if_eax_less_div1
		je _if_eax_equal_div1

		_if_eax_greater_div1 :
		add result, 1
		jmp _end

		_if_eax_less_div1 :
		jmp _end

		_if_eax_equal_div1 :
		mov esi, 2
		mov eax, result
		cdq
		div esi;			// eax - частное, edx - остаток
		cmp edx, 0
		je _res_is_even1
		jne _res_is_odd1

		_res_is_even1 :
		jmp _end

		_res_is_odd1 :
		add result, 1
		jmp _end

		_if_rem_less0 :
		mov eax, 2
		imul remainder
		cmp eax, divider
		jg _if_eax_greater_div2
		jl _if_eax_less_div2
		je _if_eax_equal_div2

		_if_eax_less_div2 :
		sub result, 1
		jmp _end

		_if_eax_greater_div2 :
		jmp _end

		_if_eax_equal_div2 :
		mov esi, 2
		mov eax, result
		cdq
		div esi;			// eax - частное, edx - остаток
		cmp edx, 0
		je _res_is_even2
		jne _res_is_odd2

		_res_is_even2 :
		jmp _end

		_res_is_odd2 :
		sub result, 1
		jmp _end

		_end :
	}
	cout << result << endl;
	return 0;
}
