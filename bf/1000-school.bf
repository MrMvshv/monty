++++++++	set #0 2 8
[
	>++++	set #1 2 4
	[
		>++	add 2 2 #2
		>+++	add 3 2 #3
		>+++	add 3 2 #4
		>+	add 1 2 #5
		<<<<-	dec #1
	]loop 4x
	>+	add 1 2 #2
	>+	add 1 2 #3
	>-	sub 1 f #4
	>>+	add 1 2 #6
	[<]	mov back to #1
	<-	dec #0
]

#0
>>>>-----.	#4 sub 5  83  S
<-----.		#3 sub 5  99  c
+++++.		#3 add 5 104  h
+++++++..	#3 add 7 111  oo
---.		#3 sub 3 108  l
>>>++.		#6 10  nl
