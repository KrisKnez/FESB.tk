      PROGRAM MAIN
        DOUBLE PRECISION   DLAMCH
        EXTERNAL           DLAMCH
      
        PRINT *
        PRINT *, 'DLAMCH results:'
        PRINT *, '========================================='
        PRINT *, 'DLAMCH("E") := ', DLAMCH('E')
        PRINT *, 'DLAMCH("S") := ', DLAMCH('S')
        PRINT *, 'DLAMCH("B") := ', DLAMCH('B')
        PRINT *, 'DLAMCH("P") := ', DLAMCH('P')
        PRINT *, 'DLAMCH("N") := ', DLAMCH('N')
        PRINT *, 'DLAMCH("R") := ', DLAMCH('R')
        PRINT *, 'DLAMCH("M") := ', DLAMCH('M')
        PRINT *, 'DLAMCH("U") := ', DLAMCH('U')
        PRINT *, 'DLAMCH("L") := ', DLAMCH('L')
        PRINT *, 'DLAMCH("O") := ', DLAMCH('O')
        PRINT *
        PRINT *, 'Press any key to continue...'
        READ  *
        STOP
      END