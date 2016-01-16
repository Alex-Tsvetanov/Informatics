set gr=B
call %CD%\..\init.bat
call %CD%\..\%gr%.bat


REM Обработва задачите
REM echo Befor exec tasks
REM echo %CD%
REM pause

call task %1 %nam1% %lt1% %cheker1% %chkpar1% %tlim1%
call task %1 %nam2% %lt2% %cheker2% %chkpar2% %tlim2%
call task %1 %nam3% %lt3% %cheker3% %chkpar3% %tlim3%

v2h groupresult.txt %1 %1\%nam1%.res %1\%nam2%.res %1\%nam3%.res

pause
exit

