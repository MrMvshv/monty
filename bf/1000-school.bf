++++++++	set #0 2 8
[
	>++++	set #1 2 4
	[
		>+++	add 3 2 #2
		>+++	add 3 2 #3
		<<-	dec #1
	]loop 4x
	>+	add 1 2 #2
	>-	sub 1 f #3
	>+	add 1 2 #4
	[<]	mov back to #1
	<-	dec #0
]

at #0
>>>-----.	#3 sub 5  83  S
<-----.		#2 sub 5  99  c
+++++.		#2 add 5 104  h
+++++++..	#2 add 7 111  oo
---.		#2 sub 3 108  l
>>++.		#4 10  nl
