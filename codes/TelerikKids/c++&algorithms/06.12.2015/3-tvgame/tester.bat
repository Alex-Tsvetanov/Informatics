for %%i in (1,2,3,4,5,6,7,8,9,10) do (
	"C:\Program Files(x86)\CodeBlocks\MinGW\bin\g++.exe" ZADACHA.cpp -o ZADACHA.exe
	ZADACHA.exe < ZADACHA.%%i.in > output.txt
	./checker/tvgame.checker.exe ZADACHA.%%i.in ZADACHA.%%i.sol output.txt 10
)
