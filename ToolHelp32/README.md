# EnumProcesses
Lista os processos do sistema utilizando a chamada CreateToolhelp32Snapshot.

## Como funciona?
A chamada CreateToolHelp32Snapshot() realiza um snapshot dos processos em execução. No caso deste programa, utilizamos o parâmetro TH32CS_SNAPPROCESS, o qual inclui todos os processos do sistema na snapshot.

Com a snapshot em mãos, podemos obter diversas informações dos processos do sistema, incluindo nome, PID, threads, classe, entre outros atributos. Clique [aqui](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/ns-tlhelp32-processentry32w) para saber mais sobre as informações que podem ser obtidas.

## Método em execução
![image](https://github.com/B0nam/BASIC-PROC-ENUM/assets/85623265/6dc83315-0eb2-4a8e-a6da-6b44717b1066)
