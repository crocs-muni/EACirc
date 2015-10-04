#include "CaesarCiphers.h"

const char* CaesarCiphers::caesarToString(int algorithm) {
    switch (algorithm) {
    case CAESAR_ACORN128:        return "ACORN - acorn128";
    case CAESAR_AEGIS128:        return "AEGIS - aegis128";
    case CAESAR_AEGIS128L:        return "AEGIS - aegis128l";
    case CAESAR_AEGIS256:        return "AEGIS - aegis256";
        //    case CAESAR_AES128AVALANCHEV1:        return "AVALANCHE - aes128avalanchev1";
        //    case CAESAR_AES192AVALANCHEV1:        return "AVALANCHE - aes192avalanchev1";
        //    case CAESAR_AES256AVALANCHEV1:        return "AVALANCHE - aes256avalanchev1";
    case CAESAR_AES128GCMV1:        return "AES-GCM - aes128gcmv1";
    case CAESAR_AES256GCMV1:        return "AES-GCM - aes256gcmv1";
    case CAESAR_AES128MARBLE4RV1:        return "Marble - aes128marble4rv1";
        //    case CAESAR_AES128N12SILCV1:        return "SILC - aes128n12silcv1";
        //    case CAESAR_AES128N8SILCV1:        return "SILC - aes128n8silcv1";
        //    case CAESAR_LED80N6SILCV1:        return "SILC - led80n6silcv1";
        //    case CAESAR_PRESENT80N6SILCV1:        return "SILC - present80n6silcv1";
    case CAESAR_AES128N12CLOCV1:        return "CLOC - aes128n12clocv1";
    case CAESAR_AES128N8CLOCV1:        return "CLOC - aes128n8clocv1";
        //    case CAESAR_TWINE80N6CLOCV1:        return "CLOC - twine80n6clocv1";
    case CAESAR_AES128OTRPV1:        return "AES-OTR - aes128otrpv1";
    case CAESAR_AES128OTRSV1:        return "AES-OTR - aes128otrsv1";
    case CAESAR_AES128POETV1AES128:        return "POET - aes128poetv1aes128";
    case CAESAR_AES128POETV1AES4:        return "POET - aes128poetv1aes4";
        //    case CAESAR_AES128CPFBV1:        return "AES-CPFB - aes128cpfbv1";
        //    case CAESAR_AES256CPFBV1:        return "AES-CPFB - aes256cpfbv1";
    case CAESAR_AES256OTRPV1:        return "AES-OTR - aes256otrpv1";
    case CAESAR_AES256OTRSV1:        return "AES-OTR - aes256otrsv1";
    case CAESAR_AESCOPAV1:        return "AES-COPA - aescopav1";
    case CAESAR_AESJAMBUV1:        return "AES-JAMBU - aesjambuv1";
    case CAESAR_AEZV1:        return "AEZ - aezv1";
    case CAESAR_AEZV3:        return "AEZ - aezv3";
    case CAESAR_ARTEMIA128V1:        return "Artemia - artemia128v1";
    case CAESAR_ARTEMIA256V1:        return "Artemia - artemia256v1";
    case CAESAR_ASCON128V1:        return "Ascon - ascon128v1";
    case CAESAR_ASCON96V1:        return "Ascon - ascon96v1";
    case CAESAR_CALICOV8:        return "Calico - calicov8";
    case CAESAR_CMCC22V1:        return "AES-CMCC - cmcc22v1";
    case CAESAR_CMCC24V1:        return "AES-CMCC - cmcc24v1";
    case CAESAR_CMCC42V1:        return "AES-CMCC - cmcc42v1";
    case CAESAR_CMCC44V1:        return "AES-CMCC - cmcc44v1";
    case CAESAR_CMCC84V1:        return "AES-CMCC - cmcc84v1";
    case CAESAR_DEOXYSEQ128128V1:        return "Deoxys - deoxyseq128128v1";
    case CAESAR_DEOXYSEQ256128V1:        return "Deoxys - deoxyseq256128v1";
    case CAESAR_DEOXYSNEQ128128V1:        return "Deoxys - deoxysneq128128v1";
    case CAESAR_DEOXYSNEQ256128V1:        return "Deoxys - deoxysneq256128v1";
    case CAESAR_ENCHILADA128V1:        return "Enchilada - enchilada128v1";
        //    case CAESAR_ENCHILADA256V1:        return "Enchilada - enchilada256v1";
    case CAESAR_HS1SIVHIV1:        return "HS1-SIV - hs1sivhiv1";
    case CAESAR_HS1SIVLOV1:        return "HS1-SIV - hs1sivlov1";
    case CAESAR_HS1SIVV1:        return "HS1-SIV - hs1sivv1";
    case CAESAR_ICEPOLE128AV1:        return "ICEPOLE - icepole128av1";
    case CAESAR_ICEPOLE128V1:        return "ICEPOLE - icepole128v1";
    case CAESAR_ICEPOLE256AV1:        return "ICEPOLE - icepole256av1";
    case CAESAR_IFEEDAES128N104V1:        return "iFeed[AES] - ifeedaes128n104v1";
    case CAESAR_IFEEDAES128N96V1:        return "iFeed[AES] - ifeedaes128n96v1";
    case CAESAR_ISCREAM12V1:        return "SCREAM - iscream12v1";
    case CAESAR_ISCREAM12V2:        return "SCREAM - iscream12v2";
    case CAESAR_ISCREAM14V1:        return "SCREAM - iscream14v1";
    case CAESAR_ISCREAM14V2:        return "SCREAM - iscream14v2";
    case CAESAR_SCREAM10V1:        return "SCREAM - scream10v1";
    case CAESAR_SCREAM10V2:        return "SCREAM - scream10v2";
    case CAESAR_SCREAM12V1:        return "SCREAM - scream12v1";
    case CAESAR_SCREAM12V2:        return "SCREAM - scream12v2";
    case CAESAR_JOLTIKEQ12864V1:        return "Joltik - joltikeq12864v1";
    case CAESAR_JOLTIKEQ6464V1:        return "Joltik - joltikeq6464v1";
    case CAESAR_JOLTIKEQ8048V1:        return "Joltik - joltikeq8048v1";
    case CAESAR_JOLTIKEQ9696V1:        return "Joltik - joltikeq9696v1";
    case CAESAR_JOLTIKNEQ12864V1:        return "Joltik - joltikneq12864v1";
    case CAESAR_JOLTIKNEQ6464V1:        return "Joltik - joltikneq6464v1";
    case CAESAR_JOLTIKNEQ8048V1:        return "Joltik - joltikneq8048v1";
    case CAESAR_JOLTIKNEQ9696V1:        return "Joltik - joltikneq9696v1";
        //    case CAESAR_JULIUSV1DRAFT:        return "Julius - juliusv1draft";
    case CAESAR_KETJEJRV1:        return "Ketje - ketjejrv1";
    case CAESAR_KETJESRV1:        return "Ketje - ketjesrv1";
    case CAESAR_KIASUEQ128V1:        return "KIASU - kiasueq128v1";
    case CAESAR_KIASUNEQ128V1:        return "KIASU - kiasuneq128v1";
    case CAESAR_LACV1:        return "LAC - lacv1";
    case CAESAR_LAKEKEYAKV1:        return "Keyak - lakekeyakv1";
    case CAESAR_OCEANKEYAKV1:        return "Keyak - oceankeyakv1";
    case CAESAR_RIVERKEYAKV1:        return "Keyak - riverkeyakv1";
    case CAESAR_SEAKEYAKV1:        return "Keyak - seakeyakv1";
    case CAESAR_MINALPHERV1:        return "Minalpher - minalpherv1";
    case CAESAR_MORUS1280128V1:        return "MORUS - morus1280128v1";
    case CAESAR_MORUS1280256V1:        return "MORUS - morus1280256v1";
    case CAESAR_MORUS640128V1:        return "MORUS - morus640128v1";
    case CAESAR_NORX3241V1:        return "NORX - norx3241v1";
    case CAESAR_NORX3261V1:        return "NORX - norx3261v1";
    case CAESAR_NORX6441V1:        return "NORX - norx6441v1";
    case CAESAR_NORX6444V1:        return "NORX - norx6444v1";
    case CAESAR_NORX6461V1:        return "NORX - norx6461v1";
    case CAESAR_OMDSHA256K128N96TAU128V1:        return "OMD - omdsha256k128n96tau128v1";
    case CAESAR_OMDSHA256K128N96TAU64V1:        return "OMD - omdsha256k128n96tau64v1";
    case CAESAR_OMDSHA256K128N96TAU96V1:        return "OMD - omdsha256k128n96tau96v1";
    case CAESAR_OMDSHA256K192N104TAU128V1:        return "OMD - omdsha256k192n104tau128v1";
    case CAESAR_OMDSHA256K256N104TAU160V1:        return "OMD - omdsha256k256n104tau160v1";
    case CAESAR_OMDSHA256K256N248TAU256V1:        return "OMD - omdsha256k256n248tau256v1";
    case CAESAR_OMDSHA512K128N128TAU128V1:        return "OMD - omdsha512k128n128tau128v1";
    case CAESAR_OMDSHA512K256N256TAU256V1:        return "OMD - omdsha512k256n256tau256v1";
    case CAESAR_OMDSHA512K512N256TAU256V1:        return "OMD - omdsha512k512n256tau256v1";
    case CAESAR_PAEQ128:        return "PAEQ - paeq128";
    case CAESAR_PAEQ128T:        return "PAEQ - paeq128t";
    case CAESAR_PAEQ128TNM:        return "PAEQ - paeq128tnm";
    case CAESAR_PAEQ160:        return "PAEQ - paeq160";
    case CAESAR_PAEQ64:        return "PAEQ - paeq64";
    case CAESAR_PAEQ80:        return "PAEQ - paeq80";
    case CAESAR_PI16CIPHER096V1:        return "Pi-Cipher - pi16cipher096v1";
    case CAESAR_PI16CIPHER128V1:        return "Pi-Cipher - pi16cipher128v1";
    case CAESAR_PI32CIPHER128V1:        return "Pi-Cipher - pi32cipher128v1";
    case CAESAR_PI32CIPHER256V1:        return "Pi-Cipher - pi32cipher256v1";
    case CAESAR_PI64CIPHER128V1:        return "Pi-Cipher - pi64cipher128v1";
    case CAESAR_PI64CIPHER256V1:        return "Pi-Cipher - pi64cipher256v1";
    case CAESAR_PI64CIPHER256V1ONEROUND:        return "Pi-Cipher - pi64cipher256v1oneround";
    case CAESAR_PI64CIPHER256V1TWOROUNDS:        return "Pi-Cipher - pi64cipher256v1tworounds";
//    case CAESAR_POLAWISV1:        return "POLAWIS - polawisv1";
    case CAESAR_PPAEV11:        return "PAES - ppaev11";
    case CAESAR_PRIMATESV1APE120:        return "PRIMATEs - primatesv1ape120";
    case CAESAR_PRIMATESV1APE80:        return "PRIMATEs - primatesv1ape80";
    case CAESAR_PRIMATESV1GIBBON120:        return "PRIMATEs - primatesv1gibbon120";
    case CAESAR_PRIMATESV1GIBBON80:        return "PRIMATEs - primatesv1gibbon80";
    case CAESAR_PRIMATESV1HANUMAN120:        return "PRIMATEs - primatesv1hanuman120";
    case CAESAR_PRIMATESV1HANUMAN80:        return "PRIMATEs - primatesv1hanuman80";
    case CAESAR_PROEST128APEV1:        return "Prost - proest128apev1";
    case CAESAR_PROEST128COPAV1:        return "Prost - proest128copav1";
    case CAESAR_PROEST128OTRV1:        return "Prost - proest128otrv1";
    case CAESAR_PROEST256APEV1:        return "Prost - proest256apev1";
    case CAESAR_PROEST256COPAV1:        return "Prost - proest256copav1";
    case CAESAR_PROEST256OTRV1:        return "Prost - proest256otrv1";
        //    case CAESAR_RAVIYOYLAV1:        return "Raviyoyla - raviyoylav1";
        //    case CAESAR_SABLIERV1:        return "Sablier - sablierv1";
        //    case CAESAR_SHELLAES128V1D4N64:        return "SHELL - shellaes128v1d4n64";
        //    case CAESAR_SHELLAES128V1D4N80:        return "SHELL - shellaes128v1d4n80";
        //    case CAESAR_SHELLAES128V1D5N64:        return "SHELL - shellaes128v1d5n64";
        //    case CAESAR_SHELLAES128V1D5N80:        return "SHELL - shellaes128v1d5n80";
        //    case CAESAR_SHELLAES128V1D6N64:        return "SHELL - shellaes128v1d6n64";
        //    case CAESAR_SHELLAES128V1D6N80:        return "SHELL - shellaes128v1d6n80";
        //    case CAESAR_SHELLAES128V1D7N64:        return "SHELL - shellaes128v1d7n64";
        //    case CAESAR_SHELLAES128V1D7N80:        return "SHELL - shellaes128v1d7n80";
        //    case CAESAR_SHELLAES128V1D8N64:        return "SHELL - shellaes128v1d8n64";
        //    case CAESAR_SHELLAES128V1D8N80:        return "SHELL - shellaes128v1d8n80";
        //    case CAESAR_SILVERV1:        return "Silver - silverv1";
        //    case CAESAR_STRIBOB192R1:        return "STRIBOB - stribob192r1";
        //    case CAESAR_TIAOXINV1:        return "Tiaoxin - tiaoxinv1";
        //    case CAESAR_TRIVIA0V1:        return "TriviA-ck - trivia0v1";
        //    case CAESAR_TRIVIA128V1:        return "TriviA-ck - trivia128v1";
        //    case CAESAR_WHEESHTV1MR3FR1T128:        return "Wheesht - wheeshtv1mr3fr1t128";
        //    case CAESAR_WHEESHTV1MR3FR1T256:        return "Wheesht - wheeshtv1mr3fr1t256";
        //    case CAESAR_WHEESHTV1MR3FR3T256:        return "Wheesht - wheeshtv1mr3fr3t256";
        //    case CAESAR_WHEESHTV1MR5FR7T256:        return "Wheesht - wheeshtv1mr5fr7t256";
        //    case CAESAR_YAES128V2:        return "YAES - yaes128v2";

        // Ciphers requiring OpenSSL
    case CAESAR_AEADAES128OCBTAGLEN128V1:        return "++AE - aeadaes128ocbtaglen128v1";
    case CAESAR_AEADAES128OCBTAGLEN64V1:        return "++AE - aeadaes128ocbtaglen64v1";
    case CAESAR_AEADAES128OCBTAGLEN96V1:        return "++AE - aeadaes128ocbtaglen96v1";
    case CAESAR_AEADAES192OCBTAGLEN128V1:        return "++AE - aeadaes192ocbtaglen128v1";
    case CAESAR_AEADAES192OCBTAGLEN64V1:        return "++AE - aeadaes192ocbtaglen64v1";
    case CAESAR_AEADAES192OCBTAGLEN96V1:        return "++AE - aeadaes192ocbtaglen96v1";
    case CAESAR_AEADAES256OCBTAGLEN128V1:        return "++AE - aeadaes256ocbtaglen128v1";
    case CAESAR_AEADAES256OCBTAGLEN64V1:        return "++AE - aeadaes256ocbtaglen64v1";
    case CAESAR_AEADAES256OCBTAGLEN96V1:        return "++AE - aeadaes256ocbtaglen96v1";
    case CAESAR_CBA1:        return "CBA - cba1";
    case CAESAR_CBA10:        return "CBA - cba10";
    case CAESAR_CBA2:        return "CBA - cba2";
    case CAESAR_CBA3:        return "CBA - cba3";
    case CAESAR_CBA4:        return "CBA - cba4";
    case CAESAR_CBA5:        return "CBA - cba5";
    case CAESAR_CBA6:        return "CBA - cba6";
    case CAESAR_CBA7:        return "CBA - cba7";
    case CAESAR_CBA8:        return "CBA - cba8";
    case CAESAR_CBA9:        return "CBA - cba9";
    case CAESAR_ELMD1000V1:        return "ELmD - elmd1000v1";
    case CAESAR_ELMD1001V1:        return "ELmD - elmd1001v1";
    case CAESAR_ELMD101270V1:        return "ELmD - elmd101270v1";
    case CAESAR_ELMD101271V1:        return "ELmD - elmd101271v1";
    case CAESAR_ELMD500V1:        return "ELmD - elmd500v1";
    case CAESAR_ELMD501V1:        return "ELmD - elmd501v1";
    case CAESAR_ELMD51270V1:        return "ELmD - elmd51270v1";
    case CAESAR_ELMD51271V1:        return "ELmD - elmd51271v1";
        // end ciphers requiring OpenSSL
    default:                    return "(unknown cipher)";
    }
}
