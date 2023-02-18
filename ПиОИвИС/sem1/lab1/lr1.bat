@chcp 65001
@echo off

setlocal

set first_path=%1
set second_path=%2

find /c /v "" < %first_path% > D:\tmp.txt 
for /f %%i in (D:\tmp.txt) do set counter1=%%i
echo %counter1%

find /c /v "" < %second_path% > D:\tmp.txt
for /f %%i in (D:\tmp.txt) do set counter2=%%i
echo %counter2%
 if %counter1%==%counter2% (
echo "Количество строк одинаковое"
goto EXIT 
) else (
echo "Количество строк разное"
goto MAIN
)
:MAIN
for /f "usebackq delims=" %%i in (%first_path%) do (
 for %%j in (%%i) do (
  set /a counter3+=1
 )
)
echo %counter3%
for /f "usebackq delims=" %%i in (%second_path%) do (
 for %%j in (%%i) do ( set /a counter4+=1))
echo %counter4%
if %counter3%==%counter4% (
echo "Количество слов одинаковое"
) else (
echo "Количество слов разное")

:EXIT
timeout 7

endlocal

pause