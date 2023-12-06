#include <windows.h>

int main(void)
{
    DWORD aProcesses[1024]; //  ARRAY PARA ARMAZENAR OS PIDS
    DWORD cbNeeded;         //  ARMAZENA O NUMERO DE BYTES RETORNADOS EM aProcesses
    DWORD cProcesses;       //  ARMAZENA O NUMERO DE PROCESSOS ENUMERADOS (NUMERO TOTAL DE BYTES / TAMANHO DE CADA ARRAY)
    int i;                  //  VARIAVEL PARA O CONTADOR UTILIZADO AO EXIBIR AS INFORMACOES DOS PROCESSOS OBTIDOS

    if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
    {
        return EXIT_FAILURE;
    }
    printf("[+] Sucess to enum processes.\n");

    cProcesses = cbNeeded / sizeof(DWORD);  //  DIVIDIMOS POR DWORD POIS ELEMENTO ARMAZENADO NO ARRAY E DESTE TIPOP
    
    for ( i = 0; i < cProcesses; i++ )
    {
        if ( aProcesses[i] != 0)
        {
            PrintProcessNameAndId( aProcesses[i] );
        }
    }

    return EXIT_SUCCESS;
}
