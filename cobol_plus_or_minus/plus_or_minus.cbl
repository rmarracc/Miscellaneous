IDENTIFICATION DIVISION.
	PROGRAM-ID. POM.

DATA DIVISION.
	WORKING-STORAGE SECTION.

	77 nb PIC 9(3).
	77 find PIC 9(3).
	77 seed PIC 9(10).

PROCEDURE DIVISION.
	DISPLAY "Choose random seed".
	ACCEPT seed FROM SYSIN.
	COMPUTE find = FUNCTION RANDOM (seed) * 100 + 1.	
	INITIALIZE nb.
	PERFORM UNTIL nb = find
		DISPLAY "Enter a number between 1 and 100"
		ACCEPT nb FROM SYSIN
		IF nb > find
			DISPLAY "It's less"
		END-IF
		IF nb < find
			DISPLAY "It's more"
		END-IF
	END-PERFORM.
	DISPLAY "You found the number, congratulations !".
	STOP RUN.