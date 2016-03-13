@echo on

REM Коренът на дървото с решенията на децата
set Root=D:\CI\C\NOI2016\1\SMG

REM Къде са тестовите данни
set testdir=D:\CI\C\NOI2016\1\tests

set RECOMPILE=
set COMPILER=1

REM Помощни файлове за генериране на отчетни данни
set toolsdir=D:\CI\C\Tools
set delim1=%toolsdir%\a1.txt
set delim2=%toolsdir%\a2.txt
set hifdelim=%toolsdir%\hif.txt
set tabdelim=%toolsdir%\tab.txt
set taskdelim=%toolsdir%\task.txt
set nocompile=%toolsdir%\a3.txt
set notfound=%toolsdir%\a4.txt
set cmplinfo=%toolsdir%\cmplinfo.txt
set rtedelim=%toolsdir%\rte.txt
set timelimit=%toolsdir%\timelimit.txt
set cpr=%toolsdir%\cmp.exe
set path=%path%;%toolsdir%

exit/B