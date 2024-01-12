# EnumWindows
Lista os processos do sistema utilizando a chamada EnumWindows().

Os créditos para esta forma "alternativa" de enumerar os processos do sistema vão para smelly__vx, fundador do vxunderground. O paper do método pode ser acessado [aqui](https://github.com/vxunderground/VXUG-Papers/blob/main/An%20Alternative%20Method%20To%20Enumerate%20Processes.pdf).

## Como funciona?
Usamos a chamada EnumWindows() para enumerarmos todas as janelas em execução e retornamos o PID da janela. A chamada em questão espera como argumento um callback, que, em nosso caso, utiliza a chamada GetProcessImageFileNameW() para obter o Path do processo.

## Observação
Como o código abre o processo dentro de um handler para obter as informações, não é possível obter o path de processos protegidos pelo sistema. Mais informações sobre permissões e acesso clique [aqui](https://learn.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights).

## Método em execução
![image](https://github.com/B0nam/BASIC-PROC-ENUM/assets/85623265/b8a606b6-c25d-41ed-a89b-3c64ff99b5df)
