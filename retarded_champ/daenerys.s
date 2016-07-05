.name "Daenerys of House Targaryen, the First of Her Name Queen of Meereen Queen of the Andals, the Rhoynar and the First Men (claimant) Lady Regnant of the Seven Kingdoms (claimant) Protector of the Realm (claimant) Khaleesi of the Great Grass Sea Breaker of Chains Mother of Dragons"
.comment "I'M ALIIIIVE"

l2:		#sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
