# BASIC-PROC-ENUM
Programa simples para enumerar processos em execução escrito em linguagem C (Windows)

## O que seria essa listagem de processos?
[INSERIR TEXTO] que listam os processos em execução no sistema, retornando o seu PID e o seu nome quando possível.

## Por que listar os processos.
Identificar os processos em execução no sistema incluindo o seu PID é extremamente útil para manipular esses processos, seja para a obtenção de dados ou para a injeção de código nos respectivos processos.

### Como funciona?
O processo de enumeração dos processos do sistema pode ser realizado de diversas maneiras, no caso deste repositório, estarei abordando três diferentes de realizar a enumeração.

As três formas aqui apresentadas utilizam as funções disponibilizadas pelo Windows para listar todos os precessos do sistema de forma relativamente simples.

Utilizando a função EnumProcesses()     // https://learn.microsoft.com/en-us/windows/win32/api/Psapi/nf-psapi-enumprocesses
Utilizando o ToolHelp32()
Utilizando a função EnumWindows()       // Créditos para smelly__vx (vxundeground creator)
