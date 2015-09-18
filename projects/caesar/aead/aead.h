#ifndef AEAD_H
#define AEAD_H

#include "acorn/acorn128/Acorn128.h"
#include "aegis/aegis128/Aegis128.h"
#include "aegis/aegis128l/Aegis128l.h"
#include "aegis/aegis256/Aegis256.h"
// #include "avalanche/aes128avalanchev1/Aes128avalanchev1.h"
// #include "avalanche/aes192avalanchev1/Aes192avalanchev1.h"
// #include "avalanche/aes256avalanchev1/Aes256avalanchev1.h"
#include "aes-gcm/aes128gcmv1/Aes128gcmv1.h"
#include "aes-gcm/aes256gcmv1/Aes256gcmv1.h"
#include "marble/aes128marble4rv1/Aes128marble4rv1.h"
// #include "silc/aes128n12silcv1/Aes128n12silcv1.h"
// #include "silc/aes128n8silcv1/Aes128n8silcv1.h"
// #include "silc/led80n6silcv1/Led80n6silcv1.h"
// #include "silc/present80n6silcv1/Present80n6silcv1.h"
#include "cloc/aes128n12clocv1/Aes128n12clocv1.h"
#include "cloc/aes128n8clocv1/Aes128n8clocv1.h"
// #include "cloc/twine80n6clocv1/Twine80n6clocv1.h"
#include "aes-otr/aes128otrpv1/Aes128otrpv1.h"
#include "aes-otr/aes128otrsv1/Aes128otrsv1.h"
#include "poet/aes128poetv1aes128/Aes128poetv1aes128.h"
#include "poet/aes128poetv1aes4/Aes128poetv1aes4.h"
// #include "aes-cpfb/aes128cpfbv1/Aes128cpfbv1.h"
// #include "aes-cpfb/aes256cpfbv1/Aes256cpfbv1.h"
#include "aes-otr/aes256otrpv1/Aes256otrpv1.h"
#include "aes-otr/aes256otrsv1/Aes256otrsv1.h"
#include "aes-copa/aescopav1/Aescopav1.h"
#include "aes-jambu/aesjambuv1/Aesjambuv1.h"
#include "aez/aezv1/Aezv1.h"
#include "aez/aezv3/Aezv3.h"
#include "artemia/artemia128v1/Artemia128v1.h"
#include "artemia/artemia256v1/Artemia256v1.h"
#include "ascon/ascon128v1/Ascon128v1.h"
#include "ascon/ascon96v1/Ascon96v1.h"
#include "calico/calicov8/Calicov8.h"
#include "aes-cmcc/cmcc22v1/Cmcc22v1.h"
#include "aes-cmcc/cmcc24v1/Cmcc24v1.h"
#include "aes-cmcc/cmcc42v1/Cmcc42v1.h"
#include "aes-cmcc/cmcc44v1/Cmcc44v1.h"
#include "aes-cmcc/cmcc84v1/Cmcc84v1.h"
#include "deoxys/deoxyseq128128v1/Deoxyseq128128v1.h"
#include "deoxys/deoxyseq256128v1/Deoxyseq256128v1.h"
#include "deoxys/deoxysneq128128v1/Deoxysneq128128v1.h"
#include "deoxys/deoxysneq256128v1/Deoxysneq256128v1.h"
#include "enchilada/enchilada128v1/Enchilada128v1.h"
// #include "enchilada/enchilada256v1/Enchilada256v1.h"
#include "hs1-siv/hs1sivhiv1/Hs1sivhiv1.h"
#include "hs1-siv/hs1sivlov1/Hs1sivlov1.h"
#include "hs1-siv/hs1sivv1/Hs1sivv1.h"
#include "icepole/icepole128av1/Icepole128av1.h"
#include "icepole/icepole128v1/Icepole128v1.h"
#include "icepole/icepole256av1/Icepole256av1.h"
#include "ifeed-aes/ifeedaes128n104v1/Ifeedaes128n104v1.h"
#include "ifeed-aes/ifeedaes128n96v1/Ifeedaes128n96v1.h"
#include "scream/iscream12v1/Iscream12v1.h"
#include "scream/iscream12v2/Iscream12v2.h"
#include "scream/iscream14v1/Iscream14v1.h"
#include "scream/iscream14v2/Iscream14v2.h"
#include "scream/scream10v1/Scream10v1.h"
#include "scream/scream10v2/Scream10v2.h"
#include "scream/scream12v1/Scream12v1.h"
#include "scream/scream12v2/Scream12v2.h"
#include "joltik/joltikeq12864v1/Joltikeq12864v1.h"
#include "joltik/joltikeq6464v1/Joltikeq6464v1.h"
#include "joltik/joltikeq8048v1/Joltikeq8048v1.h"
#include "joltik/joltikeq9696v1/Joltikeq9696v1.h"
#include "joltik/joltikneq12864v1/Joltikneq12864v1.h"
#include "joltik/joltikneq6464v1/Joltikneq6464v1.h"
#include "joltik/joltikneq8048v1/Joltikneq8048v1.h"
#include "joltik/joltikneq9696v1/Joltikneq9696v1.h"
// #include "julius/juliusv1draft/Juliusv1draft.h"
#include "ketje/ketjejrv1/Ketjejrv1.h"
#include "ketje/ketjesrv1/Ketjesrv1.h"
#include "kiasu/kiasueq128v1/Kiasueq128v1.h"
#include "kiasu/kiasuneq128v1/Kiasuneq128v1.h"
#include "lac/lacv1/Lacv1.h"
#include "keyak/lakekeyakv1/Lakekeyakv1.h"
#include "keyak/oceankeyakv1/Oceankeyakv1.h"
#include "keyak/riverkeyakv1/Riverkeyakv1.h"
#include "keyak/seakeyakv1/Seakeyakv1.h"
#include "minalpher/minalpherv1/Minalpherv1.h"
#include "morus/morus1280128v1/Morus1280128v1.h"
#include "morus/morus1280256v1/Morus1280256v1.h"
#include "morus/morus640128v1/Morus640128v1.h"
#include "norx/norx3241v1/Norx3241v1.h"
#include "norx/norx3261v1/Norx3261v1.h"
#include "norx/norx6441v1/Norx6441v1.h"
#include "norx/norx6444v1/Norx6444v1.h"
#include "norx/norx6461v1/Norx6461v1.h"
#include "omd/omdsha256k128n96tau128v1/Omdsha256k128n96tau128v1.h"
#include "omd/omdsha256k128n96tau64v1/Omdsha256k128n96tau64v1.h"
#include "omd/omdsha256k128n96tau96v1/Omdsha256k128n96tau96v1.h"
#include "omd/omdsha256k192n104tau128v1/Omdsha256k192n104tau128v1.h"
#include "omd/omdsha256k256n104tau160v1/Omdsha256k256n104tau160v1.h"
#include "omd/omdsha256k256n248tau256v1/Omdsha256k256n248tau256v1.h"
#include "omd/omdsha512k128n128tau128v1/Omdsha512k128n128tau128v1.h"
#include "omd/omdsha512k256n256tau256v1/Omdsha512k256n256tau256v1.h"
#include "omd/omdsha512k512n256tau256v1/Omdsha512k512n256tau256v1.h"
#include "paeq/paeq128/Paeq128.h"
#include "paeq/paeq128t/Paeq128t.h"
#include "paeq/paeq128tnm/Paeq128tnm.h"
#include "paeq/paeq160/Paeq160.h"
#include "paeq/paeq64/Paeq64.h"
#include "paeq/paeq80/Paeq80.h"
#include "pi-cipher/pi16cipher096v1/Pi16cipher096v1.h"
#include "pi-cipher/pi16cipher128v1/Pi16cipher128v1.h"
#include "pi-cipher/pi32cipher128v1/Pi32cipher128v1.h"
#include "pi-cipher/pi32cipher256v1/Pi32cipher256v1.h"
#include "pi-cipher/pi64cipher128v1/Pi64cipher128v1.h"
#include "pi-cipher/pi64cipher256v1/Pi64cipher256v1.h"
#include "pi-cipher/pi64cipher256v1oneround/Pi64cipher256v1oneround.h"
#include "pi-cipher/pi64cipher256v1tworounds/Pi64cipher256v1tworounds.h"
// #include "polawis/polawisv1/Polawisv1.h"
// #include "paes/ppaev11/Ppaev11.h"
// #include "primates/primatesv1ape120/Primatesv1ape120.h"
// #include "primates/primatesv1ape80/Primatesv1ape80.h"
// #include "primates/primatesv1gibbon120/Primatesv1gibbon120.h"
// #include "primates/primatesv1gibbon80/Primatesv1gibbon80.h"
// #include "primates/primatesv1hanuman120/Primatesv1hanuman120.h"
// #include "primates/primatesv1hanuman80/Primatesv1hanuman80.h"
// #include "prost/proest128apev1/Proest128apev1.h"
// #include "prost/proest128copav1/Proest128copav1.h"
// #include "prost/proest128otrv1/Proest128otrv1.h"
// #include "prost/proest256apev1/Proest256apev1.h"
// #include "prost/proest256copav1/Proest256copav1.h"
// #include "prost/proest256otrv1/Proest256otrv1.h"
// #include "raviyoyla/raviyoylav1/Raviyoylav1.h"
// #include "sablier/sablierv1/Sablierv1.h"
// #include "shell/shellaes128v1d4n64/Shellaes128v1d4n64.h"
// #include "shell/shellaes128v1d4n80/Shellaes128v1d4n80.h"
// #include "shell/shellaes128v1d5n64/Shellaes128v1d5n64.h"
// #include "shell/shellaes128v1d5n80/Shellaes128v1d5n80.h"
// #include "shell/shellaes128v1d6n64/Shellaes128v1d6n64.h"
// #include "shell/shellaes128v1d6n80/Shellaes128v1d6n80.h"
// #include "shell/shellaes128v1d7n64/Shellaes128v1d7n64.h"
// #include "shell/shellaes128v1d7n80/Shellaes128v1d7n80.h"
// #include "shell/shellaes128v1d8n64/Shellaes128v1d8n64.h"
// #include "shell/shellaes128v1d8n80/Shellaes128v1d8n80.h"
// #include "silver/silverv1/Silverv1.h"
// #include "stribob/stribob192r1/Stribob192r1.h"
// #include "tiaoxin/tiaoxinv1/Tiaoxinv1.h"
// #include "trivia-ck/trivia0v1/Trivia0v1.h"
// #include "trivia-ck/trivia128v1/Trivia128v1.h"
// #include "wheesht/wheeshtv1mr3fr1t128/Wheeshtv1mr3fr1t128.h"
// #include "wheesht/wheeshtv1mr3fr1t256/Wheeshtv1mr3fr1t256.h"
// #include "wheesht/wheeshtv1mr3fr3t256/Wheeshtv1mr3fr3t256.h"
// #include "wheesht/wheeshtv1mr5fr7t256/Wheeshtv1mr5fr7t256.h"
// #include "yaes/yaes128v2/Yaes128v2.h"

#ifdef WITH_OPENSSL
	#include "ae/aeadaes128ocbtaglen128v1/Aeadaes128ocbtaglen128v1.h"
	#include "ae/aeadaes128ocbtaglen64v1/Aeadaes128ocbtaglen64v1.h"
	#include "ae/aeadaes128ocbtaglen96v1/Aeadaes128ocbtaglen96v1.h"
	#include "ae/aeadaes192ocbtaglen128v1/Aeadaes192ocbtaglen128v1.h"
	#include "ae/aeadaes192ocbtaglen64v1/Aeadaes192ocbtaglen64v1.h"
	#include "ae/aeadaes192ocbtaglen96v1/Aeadaes192ocbtaglen96v1.h"
	#include "ae/aeadaes256ocbtaglen128v1/Aeadaes256ocbtaglen128v1.h"
	#include "ae/aeadaes256ocbtaglen64v1/Aeadaes256ocbtaglen64v1.h"
	#include "ae/aeadaes256ocbtaglen96v1/Aeadaes256ocbtaglen96v1.h"
	#include "cba/cba1/Cba1.h"
	#include "cba/cba10/Cba10.h"
	#include "cba/cba2/Cba2.h"
	#include "cba/cba3/Cba3.h"
	#include "cba/cba4/Cba4.h"
	#include "cba/cba5/Cba5.h"
	#include "cba/cba6/Cba6.h"
	#include "cba/cba7/Cba7.h"
	#include "cba/cba8/Cba8.h"
	#include "cba/cba9/Cba9.h"
	#include "elmd/elmd1000v1/Elmd1000v1.h"
	#include "elmd/elmd1001v1/Elmd1001v1.h"
	#include "elmd/elmd101270v1/Elmd101270v1.h"
	#include "elmd/elmd101271v1/Elmd101271v1.h"
	#include "elmd/elmd500v1/Elmd500v1.h"
	#include "elmd/elmd501v1/Elmd501v1.h"
	#include "elmd/elmd51270v1/Elmd51270v1.h"
	#include "elmd/elmd51271v1/Elmd51271v1.h"
#endif

#endif // AEAD_H
