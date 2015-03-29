# Edit Distance-Enhanced
The problems faced in the standard edit distance algorithm was of time and space complexity issues. For example the edit distance between words (fondam, albanian) made a 6*8 matrix of the memory plus 2 initialization arrays Which held place in memory Specially if words or sequences grow large.

Proposed Solution :

An algorithm which is space efficient compared to the standard. Notice that each cell in the matrix ONLY need 3 surrounding cells to obtain the minimum result wanted using the minimum function So if we managed to do a linear computation of for each cell A one dimensional array the holds the previous needed characters. This array's length is determined by the length of the smaller phrase+2.

E(i,j) = Minimum function ( array[0] + diff, array[1] +1, array[length-1] +1 )
