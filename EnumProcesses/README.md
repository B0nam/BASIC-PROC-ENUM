# EnumProcesses
Lista os processos do sistema utilizando a chamada EnumProcesses.

## Como funciona?
Em resumo, utilizamos a chamada EnumProcesses para obtermos todos os PID's em execução no momento da chamada. Com os PID's em mãos, abrimos cada uma dos processos e verificamos o seu PATH.

## Observação
Como o código abre o processo dentro de um handler para obter as informações, não é possivel obter o path de processos protegidos pelo sistema. Mais informações sobre permissões e acesso clique [aqui.](https://learn.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights)

## Método em execução
![image](https://github.com/B0nam/BASIC-PROC-ENUM/assets/85623265/483289f9-44ad-4d43-ac4a-52b8c70de9f1)
