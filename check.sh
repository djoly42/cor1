#!/bin/sh
echo "Debut du test\n"

echo "Generation des .cor\n"
./goinfre/asm goinfre/champions/championships/2014/bguy/sam_2.0.s
./goinfre/asm goinfre/champions/championships/2014/bjacob/doge.s
./goinfre/asm goinfre/champions/championships/2014/brandazz/Rainbow_dash.s
./goinfre/asm goinfre/champions/championships/2014/cdivry/youforkmytralala.s
./goinfre/asm goinfre/champions/championships/2014/clafleur/big_feet.s
./goinfre/asm goinfre/champions/championships/2014/dcohen/loose.s
./goinfre/asm goinfre/champions/championships/2014/ekocevar/mandragore.s
./goinfre/asm goinfre/champions/championships/2014/esusseli/gedeon.s
./goinfre/asm goinfre/champions/championships/2014/evlasova/terminator.s
./goinfre/asm goinfre/champions/championships/2014/fcorre/ultimate-surrender.s
./goinfre/asm goinfre/champions/championships/2014/gbir/_.s
./goinfre/asm goinfre/champions/championships/2014/gjestin/salamahenagalabadoun.s
./goinfre/asm goinfre/champions/championships/2014/gleger/Machine-gun.s
./goinfre/asm goinfre/champions/championships/2014/gmange/corelol.s
./goinfre/asm goinfre/champions/championships/2014/gpetrov/MarineKing.s
./goinfre/asm goinfre/champions/championships/2014/gudepard/Kappa.s
./goinfre/asm goinfre/champions/championships/2014/hmichals/Wall.s
./goinfre/asm goinfre/champions/championships/2014/hmoutaou/Misaka_Mikoto.s
./goinfre/asm goinfre/champions/championships/2014/kelickel/Varimathras.s
./goinfre/asm goinfre/champions/championships/2014/kmonrose/justin_bee.s
./goinfre/asm goinfre/champions/championships/2014/ldesgoui/_honeybadger.s
./goinfre/asm goinfre/champions/championships/2014/lseguin/skynet.s
./goinfre/asm goinfre/champions/championships/2014/lsirigna/live.s
./goinfre/asm goinfre/champions/championships/2014/mbacoux/meowluigi.s
./goinfre/asm goinfre/champions/championships/2014/mconraux/dubo.s
./goinfre/asm goinfre/champions/championships/2014/rabid-on/jinx.s
./goinfre/asm goinfre/champions/championships/2014/rmasse/THUNDER.s
./goinfre/asm goinfre/champions/championships/2014/sbuono/Asombra.s
./goinfre/asm goinfre/champions/championships/2014/srabah-m/littlepuppy.s
./goinfre/asm goinfre/champions/championships/2014/tdemay/champ.s
./goinfre/asm goinfre/champions/championships/2014/vrey/darksasuke.s
./goinfre/asm goinfre/champions/championships/2014/ybouvet/casimir.s
./goinfre/asm goinfre/champions/examples/bee_gees.s
./goinfre/asm goinfre/champions/examples/bigzork.s
./goinfre/asm goinfre/champions/examples/fluttershy.s
./goinfre/asm goinfre/champions/examples/helltrain.s
./goinfre/asm goinfre/champions/examples/turtle.s
./goinfre/asm goinfre/champions/examples/zork.s

./asm goinfre/champions/championships/2014/bguy/sam_2.0.s
./asm goinfre/champions/championships/2014/bjacob/doge.s
./asm goinfre/champions/championships/2014/brandazz/Rainbow_dash.s
./asm goinfre/champions/championships/2014/cdivry/youforkmytralala.s
./asm goinfre/champions/championships/2014/clafleur/big_feet.s
./asm goinfre/champions/championships/2014/dcohen/loose.s
./asm goinfre/champions/championships/2014/ekocevar/mandragore.s
./asm goinfre/champions/championships/2014/esusseli/gedeon.s
./asm goinfre/champions/championships/2014/evlasova/terminator.s
./asm goinfre/champions/championships/2014/fcorre/ultimate-surrender.s
./asm goinfre/champions/championships/2014/gbir/_.s
./asm goinfre/champions/championships/2014/gjestin/salamahenagalabadoun.s
./asm goinfre/champions/championships/2014/gleger/Machine-gun.s
./asm goinfre/champions/championships/2014/gmange/corelol.s
./asm goinfre/champions/championships/2014/gpetrov/MarineKing.s
./asm goinfre/champions/championships/2014/gudepard/Kappa.s
./asm goinfre/champions/championships/2014/hmichals/Wall.s
./asm goinfre/champions/championships/2014/hmoutaou/Misaka_Mikoto.s
./asm goinfre/champions/championships/2014/kelickel/Varimathras.s
./asm goinfre/champions/championships/2014/kmonrose/justin_bee.s
./asm goinfre/champions/championships/2014/ldesgoui/_honeybadger.s
./asm goinfre/champions/championships/2014/lseguin/skynet.s
./asm goinfre/champions/championships/2014/lsirigna/live.s
./asm goinfre/champions/championships/2014/mbacoux/meowluigi.s
./asm goinfre/champions/championships/2014/mconraux/dubo.s
./asm goinfre/champions/championships/2014/rabid-on/jinx.s
./asm goinfre/champions/championships/2014/rmasse/THUNDER.s
./asm goinfre/champions/championships/2014/sbuono/Asombra.s
./asm goinfre/champions/championships/2014/srabah-m/littlepuppy.s
./asm goinfre/champions/championships/2014/tdemay/champ.s
./asm goinfre/champions/championships/2014/vrey/darksasuke.s
./asm goinfre/champions/championships/2014/ybouvet/casimir.s
./asm goinfre/champions/examples/bee_gees.s
./asm goinfre/champions/examples/bigzork.s
./asm goinfre/champions/examples/fluttershy.s
./asm goinfre/champions/examples/helltrain.s
./asm goinfre/champions/examples/turtle.s
./asm goinfre/champions/examples/zork.s

echo "Execution du diff\n"
diff goinfre/champions/championships/2014/bguy/sam_2.0.cor goinfre/champions/championships/2014/bguy/sam_2.0.s.cor
diff goinfre/champions/championships/2014/bjacob/doge.cor goinfre/champions/championships/2014/bjacob/doge.s.cor
diff goinfre/champions/championships/2014/brandazz/Rainbow_dash.cor goinfre/champions/championships/2014/brandazz/Rainbow_dash.s.cor
diff goinfre/champions/championships/2014/cdivry/youforkmytralala.cor goinfre/champions/championships/2014/cdivry/youforkmytralala.s.cor
diff goinfre/champions/championships/2014/clafleur/big_feet.cor goinfre/champions/championships/2014/clafleur/big_feet.s.cor
diff goinfre/champions/championships/2014/dcohen/loose.cor goinfre/champions/championships/2014/dcohen/loose.s.cor
diff goinfre/champions/championships/2014/ekocevar/mandragore.cor goinfre/champions/championships/2014/ekocevar/mandragore.s.cor
diff goinfre/champions/championships/2014/esusseli/gedeon.cor goinfre/champions/championships/2014/esusseli/gedeon.s.cor
diff goinfre/champions/championships/2014/evlasova/terminator.cor goinfre/champions/championships/2014/evlasova/terminator.s.cor
diff goinfre/champions/championships/2014/fcorre/ultimate-surrender.cor goinfre/champions/championships/2014/fcorre/ultimate-surrender.s.cor
diff goinfre/champions/championships/2014/gbir/_.cor goinfre/champions/championships/2014/gbir/_.s.cor
diff goinfre/champions/championships/2014/gjestin/salamahenagalabadoun.cor goinfre/champions/championships/2014/gjestin/salamahenagalabadoun.s.cor
diff goinfre/champions/championships/2014/gleger/Machine-gun.cor goinfre/champions/championships/2014/gleger/Machine-gun.s.cor
diff goinfre/champions/championships/2014/gmange/corelol.cor goinfre/champions/championships/2014/gmange/corelol.s.cor
diff goinfre/champions/championships/2014/gpetrov/MarineKing.cor goinfre/champions/championships/2014/gpetrov/MarineKing.s.cor
diff goinfre/champions/championships/2014/gudepard/Kappa.cor goinfre/champions/championships/2014/gudepard/Kappa.s.cor
diff goinfre/champions/championships/2014/hmichals/Wall.cor goinfre/champions/championships/2014/hmichals/Wall.s.cor
diff goinfre/champions/championships/2014/hmoutaou/Misaka_Mikoto.cor goinfre/champions/championships/2014/hmoutaou/Misaka_Mikoto.s.cor
diff goinfre/champions/championships/2014/kelickel/Varimathras.cor goinfre/champions/championships/2014/kelickel/Varimathras.s.cor
diff goinfre/champions/championships/2014/kmonrose/justin_bee.cor goinfre/champions/championships/2014/kmonrose/justin_bee.s.cor
diff goinfre/champions/championships/2014/ldesgoui/_honeybadger.cor goinfre/champions/championships/2014/ldesgoui/_honeybadger.s.cor
diff goinfre/champions/championships/2014/lseguin/skynet.cor goinfre/champions/championships/2014/lseguin/skynet.s.cor
diff goinfre/champions/championships/2014/lsirigna/live.cor goinfre/champions/championships/2014/lsirigna/live.s.cor
diff goinfre/champions/championships/2014/mbacoux/meowluigi.cor goinfre/champions/championships/2014/mbacoux/meowluigi.s.cor
diff goinfre/champions/championships/2014/mconraux/dubo.cor goinfre/champions/championships/2014/mconraux/dubo.s.cor
diff goinfre/champions/championships/2014/rabid-on/jinx.cor goinfre/champions/championships/2014/rabid-on/jinx.s.cor
diff goinfre/champions/championships/2014/rmasse/THUNDER.cor goinfre/champions/championships/2014/rmasse/THUNDER.s.cor
diff goinfre/champions/championships/2014/sbuono/Asombra.cor goinfre/champions/championships/2014/sbuono/Asombra.s.cor
diff goinfre/champions/championships/2014/srabah-m/littlepuppy.cor goinfre/champions/championships/2014/srabah-m/littlepuppy.s.cor
diff goinfre/champions/championships/2014/tdemay/champ.cor goinfre/champions/championships/2014/tdemay/champ.s.cor
diff goinfre/champions/championships/2014/vrey/darksasuke.cor goinfre/champions/championships/2014/vrey/darksasuke.s.cor
diff goinfre/champions/championships/2014/ybouvet/casimir.cor goinfre/champions/championships/2014/ybouvet/casimir.s.cor
diff goinfre/champions/examples/bee_gees.cor goinfre/champions/examples/bee_gees.s.cor
diff goinfre/champions/examples/bigzork.cor goinfre/champions/examples/bigzork.s.cor
diff goinfre/champions/examples/fluttershy.cor goinfre/champions/examples/fluttershy.s.cor
diff goinfre/champions/examples/helltrain.cor goinfre/champions/examples/helltrain.s.cor
diff goinfre/champions/examples/turtle.cor goinfre/champions/examples/turtle.s.cor
diff goinfre/champions/examples/zork.cor goinfre/champions/examples/zork.s.cor
