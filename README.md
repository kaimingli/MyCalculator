# MyCalculator
## a simple calculator implemented by lexical and parser

support add sub mul div nag pow, but num can only have one '.', i don't check it
actuclly, i nearly don't do too much wrong check


### now, i give the grammar:</br>
E->E+T | E-T | T</br>
T->T* F | T/F | F</br>
F->-N | N</br>
N->M^N | M</br>
M->(E) | id</br>

### eliminate left recursion:</br>
E ->TE'</br>
E'->+TE' | -TE' |~ </br>
T ->FT'</br>
T'->* FT' | /FT' |~ </br>
F ->-N | N</br>
N ->MN'</br>
N'->^N |~ </br>
M ->(E)|id</br>

### first and follow:</br>
first(N) = first(M) = {(,id}</br>
first(E) = first(T) = first(F) = {-,(,id}</br>
first(E') = {+,-,~}</br>
first(T') = {* ,/,~}</br>
first(N') = {^,~}</br>
follow(E) = follow(E') = {),~}</br>
follow(T) = follow(T') = {+,-,),~}</br>
follow(F) = follow(N) = follow(N') = {* ,/,+,-,),~}</br>
follow(M) = {^,* ,/,+,-,),~}</br>

### Analysis table:</br>
	  id	  +   -	  *	    /	  ^	  ( 	)	  $</br>
E         TE’         TE’				       TE’</br>
E’		  +TE’	-TE’</br>
T	  FT’		    FT’				        FT’</br>
T’  				      *FT’  /FT’</br>
F	  N		      -N				        N</br>
N	  MN						              MN’</br>
N’  							          ^N</br>
M	  Id						              (E)</br>

hope can help you
