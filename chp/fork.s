.name "Fork"
.comment "I'M A FORK"

		ld %64, r4
		ld %4, r5
		ld %2, r6
l2:		sti r1, %:live, %1
		;st r1, r2
		;st r2, 100
		;st r2, -100
		;st r2, 511
		;st r2, -511
		;st r2, 512
		;st r2, -512
		add r4, r5, r4
		sti r6, r4, r5
		add r1, r2, r1
		and r3, %0, r3

live:	live %1453435
		fork %:l2
		zjmp %:live
