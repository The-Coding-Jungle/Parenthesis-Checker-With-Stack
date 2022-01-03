IF NOT EXIST build mkdir build
IF NOT EXIST data mkdir data 

gcc .\src\main.exe -o .\build\main.exe
.\build\main.exe