function result_of_function_f = f (arr1, arr2)
	result_of_function_f = sum (arr1 .* arr2);
endfunction

right_side_of_eq = [175231511,46012106,293888266,414081012,725440535];
x   = [20,-18,12,-9];
eq1 = [6456,14482,80443,91712];
eq2 = [46603,85084,90886,43276];
eq3 = [73805,76890,42862,62163];
eq4 = [6324,15062,37884,17771];
eq5 = [53674,13346,95893,53116];
f(eq1, x) - right_side_of_eq(1)
f(eq2, x) - right_side_of_eq(2)
f(eq3, x) - right_side_of_eq(3)
f(eq4, x) - right_side_of_eq(4)
f(eq5, x) - right_side_of_eq(5)
