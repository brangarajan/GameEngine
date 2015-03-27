rmdir /S /Q Debug 
rmdir /S /Q Release 
rmdir /S /Q ipch 
del /F /S /A:H *.suo 
del /F /S *.sdf
 
for /d %%D in (*) do ( 
echo %%~fD 
rmdir /S /Q %%~D\Debug 
rmdir /S /Q %%~D\Release 
rmdir /S /Q %%~D\bin 
rmdir /S /Q %%~D\obj 
)