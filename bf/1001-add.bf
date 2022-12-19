,>,	take 2 #0 #1

>++++++	#2 add 6
[
	>++++++++	#3 add 8
	<-	#2 dec
]
(loop 6x8
#3 = 48  #0 = n1  #1 = n2)

>	#3
[
	-	#3 dec
	<<-	#1 dec
	>>	#3
](loop till #3 = 0)

<<	#1
[
	-	#1 dec
	<+	#0 inc
	>	#1
](loop till #1 = 0)
<.
