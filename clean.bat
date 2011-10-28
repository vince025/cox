@echo off

echo -----------------------------------
echo clean project/coide_gen/rvmdk/ewarm
@for /r . %%a in (.) do (
    @if exist "%%a\coide_gen" rd /s /q "%%a\coide_gen"
    @if exist "%%a\Debug_Flash" rd /s /q "%%a\Debug_Flash"
    @if exist "%%a\Debug_Ram" rd /s /q "%%a\Debug_Ram"
    @if exist "%%a\ewarm\settings" rd /s /q "%%a\ewarm\settings"
    @if exist "%%a\Debug" rd /s /q "%%a\Debug"
    @if exist "%%a\Release" rd /s /q "%%a\Release"
    @if exist "%%a\*.dep" del /q "%%a\*.dep"
    @if exist "%%a\obj" rd /s /q "%%a\obj"
    @if exist "%%a\lst" rd /s /q "%%a\lst"
    @if exist "%%a\*.uvgui.*" del /q "%%a\*.uvgui.*"
    @if exist "%%a\*.bak" del /q "%%a\*.bak" 
    @if exist "%%a\*.o" del /q "%%a\*.o" 
    @if exist "%%a\*.d" del /q "%%a\*.d"
)
@echo completed
echo -----------------------------------

echo -----------------------------------
echo clean CoX\CoX_Peripheral\CoX_Peripheral_NUC1xx\all\project\template\coide(genernate) 
rd /s /q "CoX\CoX_Peripheral\CoX_Peripheral_NUC1xx\all\project\template\coide" >>nul
echo completed
echo -----------------------------------


echo -----------------------------------
echo clean CoX.Peripheral.NUC1xx.doxygen(html/rtf)
del /q "CoX\CoX_Peripheral\CoX_Peripheral_NUC1xx\doc\gen\doxy.log" >>nul
rd /s /q "CoX\CoX_Peripheral\CoX_Peripheral_NUC1xx\doc\en" >>nul
echo completed
echo -----------------------------------

pause