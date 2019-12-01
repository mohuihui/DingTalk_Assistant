@echo off  
color 2f  
title VC++ Project Clean run at %DATE%_%TIME%   
::mode con:cols=70 lines=30  
  
set fExts=ncb.opt.obj.ilk.pdb.plg.aps.bsc.tmp.trc.pch.idb.exp.sbr.positions.user.user.htm
set fExts10=.sdf.usr.*log.suo.ipch  
  
set fileExts=%fExts%%fExts10%  
echo [1] Cleanning files.  
:loop  
FOR /F "usebackq delims=. tokens=1,*" %%i IN (`echo %fileExts%`) DO (  
if not "%%j"=="" (del /S *.%%i&set fileExts=%%j&goto loop) else del /S *.%%i&goto endloop  
)  
:endloop  

FOR /R . %%a IN (.) DO @IF EXIST "%%a\DEBUG" RD /S /Q "%%a\DEBUG"
FOR /R . %%a IN (.) DO @IF EXIST "%%a\Release" RD /S /Q "%%a\Release"

color 4f  
echo [2] Command complected.  
  
:Exit  
pause>nul