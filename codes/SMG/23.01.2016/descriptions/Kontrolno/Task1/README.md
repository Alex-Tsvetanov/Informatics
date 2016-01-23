<html>
<head>
<script type="text/javascript" src="http://latex.codecogs.com/latexit.js"></script>
<script type="text/javascript">
LatexIT.add('body',true);
</script>
<meta charset="UTF-8"> 
<style>
table, th, td {
border: 1px solid black;
}
</style>
</head>
<body>
<h1>Задача 1:</h1>
Дадена е двойка редици:<br>
$A_1 = {a_1_,_1 , a_1_,_2,......., a_1_,_n_1$<br>
$A_2 = {a_2_,_1 , a_2_,_2,......., a_2_,_n_2$<br><br>
Елементите на всяка редица са различни цели, положителни числа. Двойката се нарича „сливаема”, ако съществува редица от различни числа:<br> <br>
$B = {b_1, b_2, ... , b_n}$,  такава че всяка от редиците $A_1$ и $A_2$ се явява подредица на B.<br><br>
<b>Определение:</b><br>Редицата $a_1, a_2, a_3, ... , a_m$ се нарича подредица на редицата $b_1, b_2, b_3, ... , b_n$, ако m ≤ n и съществуват индекси $ i_1 < i_2 < i_3 < ... < i_m $ , такива че $ a_1 = b_i_._1, a_2 = b_i_._2, ... , a_m = b_i_._m $<br><br>
Напишете програма <b>2rows</b>, която, за съвкупност от 5 двойки от редици, определя за всяка от тях дали е сливаема или не.<br><br>
<b>Вход:</b><br>
На стандартния вход се подава N и N групи от данни – по една за всяка двойка редици. Всяка група се състои от два реда – по един за всяка редица. Първото число на реда задава броя на елементите в редицата, а след това идват самите елементи. Числата в реда са разделени с по един интерва.<br><br>
<b>Изход:</b><br>
На стандартния изход трябва да изведете низ с дължина N, в който на   съответната позиция стои 0 (нула), ако съответната двойка редици не е сливаема и 1, ако е сливаем.<br><br>
<b>Ограничени:</b><br>
1 ≤ N ≤ 10000<br>
1 ≤ Брой на елементите в редица ≤ 10000<br><br>
Елементите на всяка редица са различни цели, положителни числа между 1 и $10^9$.<br><br>
<b>ПРИМЕР:</b><br>
<table 
style="width:50%">
<tr>
<td><b>Вход:</b></td>
<td><b>Изход:</b></td>
</tr>
<tr>
<td>
5<br>
3 1 2 3<br>
4 1 3 5 6<br>
3 5 1 4<Br>
4 150 1 20 5<Br>
4 1 5 6 2<br>
3 2 1 6<br>
5 100 20 45 10 3<br>
4 3 100 80 10<br>
5 90 1 4 8 80<br>
5 90 1 8 100 5<br>
</td>
<td>1 0 0 0 1<br><br><br><br><br><br><br><br><br><br><br></td>
</tr>
</table> 
</body>
</html>
