# MyCalculator
##a simple calculator implemented by lexical and parser

support add sub mul div nag pow, but num can only have one '.', i don't check it
actuclly, i nearly don't do too much wrong check


###now, i give the grammar:
E->E+T | E-T | T
T->T* F | T/F | F
F->-N | N
N->M^N | M
M->(E) | id

###eliminate left recursion:
E ->TE'
E'->+TE' | -TE' | ~
T ->FT'
T'->* FT' | /FT' |~
F ->-N | N
N ->MN'
N'->^N | ~
M ->(E)|id

###first and follow:
first(N) = first(M) = {(,id}
first(E) = first(T) = first(F) = {-,(,id}
first(E') = {+,-,~}
first(T') = {* ,/,~}
first(N') = {^,~}
follow(E) = follow(E') = {),~}
follow(T) = follow(T') = {+,-,),~}
follow(F) = follow(N) = follow(N') = {* ,/,+,-,),~}
follow(M) = {^,* ,/,+,-,),~}

###Analysis table:
	  id	  +   -	  *	    /	  ^	  ( 	)	  $
E	  TE’		    TE’				       TE’
E’		  +TE’	-TE’
T	  FT’		    FT’				        FT’
T’  				      *FT’  /FT’
F	  N		      -N				        N
N	  MN						              MN’
N’  							          ^N
M	  Id						              (E)

hope can help you
