/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>

#include "common_test.h"
#include <mbedtls/md.h>

/**@brief SHA test vectors can be found on NIST web pages.
 *
 * https://csrc.nist.gov/Projects/Cryptographic-Algorithm-Validation-Program/Secure-Hashing
 */

const char flash_data_sha_512[4096] = { "1234567890" };

/* SHA512 - Based on NIST CAVS 11.0 */
ITEM_REGISTER(test_vector_hash_512_data,
	      test_vector_hash_t test_vector_sha512_invalid) = {
	.digest_type = MBEDTLS_MD_SHA512,
	.expected_err_code = 0,
	.expected_result = EXPECTED_TO_FAIL,
	.p_test_vector_name = TV_NAME("SHA512 invalid hash"),
	.p_input =
		"d1ca70ae1279ba0b918157558b4920d6b7fba8a06be515170f202fafd36fb7f79d69fa"
		"d745dba6150568db1e2b728504113eeac34f527fc82f2200b462ecbf5d",
	.p_expected_output =
		"046e46623912b3932b8d662ab42583423843206301b58bf20ab6d76fd47f1cbbcf421d"
		"f536ecd7e56db5354e7e0f98822d2129c197f6f0f222b8ec5231f3967d"
};

/* SHA512 - NIST CAVS 11.0 */
ITEM_REGISTER(test_vector_hash_512_data,
	      test_vector_hash_t test_vector_sha512_0) = {
	.digest_type = MBEDTLS_MD_SHA512,
	.expected_err_code = 0,
	.expected_result = EXPECTED_TO_PASS,
	.p_test_vector_name = TV_NAME("SHA512 message_len=0"),
	.p_input = "",
	.p_expected_output =
		"cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d1"
		"3c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e"
};

/* SHA512 - NIST CAVS 11.0 */
ITEM_REGISTER(test_vector_hash_512_data,
	      test_vector_hash_t test_vector_sha512_4) = {
	.digest_type = MBEDTLS_MD_SHA512,
	.expected_err_code = 0,
	.expected_result = EXPECTED_TO_PASS,
	.p_test_vector_name = TV_NAME("SHA512 message_len=4"),
	.p_input = "a801e94b",
	.p_expected_output =
		"dadb1b5a27f9fece8d86adb2a51879beb1787ff28f4e8ce162cad7fee0f942efcabbf7"
		"38bc6f797fc7cc79a3a75048cd4c82ca0757a324695bfb19a557e56e2f"
};

/* SHA512 - NIST CAVS 11.0 */
ITEM_REGISTER(test_vector_hash_512_data,
	      test_vector_hash_t test_vector_sha512_64) = {
	.digest_type = MBEDTLS_MD_SHA512,
	.expected_err_code = 0,
	.expected_result = EXPECTED_TO_PASS,
	.p_test_vector_name = TV_NAME("SHA512 message_len=64"),
	.p_input =
		"c1ca70ae1279ba0b918157558b4920d6b7fba8a06be515170f202fafd36fb7f79d69fa"
		"d745dba6150568db1e2b728504113eeac34f527fc82f2200b462ecbf5d",
	.p_expected_output =
		"046e46623912b3932b8d662ab42583423843206301b58bf20ab6d76fd47f1cbbcf421d"
		"f536ecd7e56db5354e7e0f98822d2129c197f6f0f222b8ec5231f3967d"
};

/* SHA512 - NIST CAVS 11.0 */
ITEM_REGISTER(test_vector_hash_512_data,
	      test_vector_hash_t test_vector_sha512_955) = {
	.digest_type = MBEDTLS_MD_SHA512,
	.expected_err_code = 0,
	.expected_result = EXPECTED_TO_PASS,
	.p_test_vector_name = TV_NAME("SHA512 message_len=955"),
	.p_input =
		"990d1ae71a62d7bda9bfdaa1762a68d296eee72a4cd946f287a898fbabc002ea941fd8"
		"d4d991030b4d27a637cce501a834bb95eab1b7889a3e784c7968e67cbf552006b206b6"
		"8f76d9191327524fcc251aeb56af483d10b4e0c6c5e599ee8c0fe4faeca8293844a854"
		"7c6a9a90d093f2526873a19ad4a5e776794c68c742fb834793d2dfcb7fea46c63af4b7"
		"0fd11cb6e41834e72ee40edb067b292a794990c288d5007e73f349fb383af6a756b830"
		"1ad6e5e0aa8cd614399bb3a452376b1575afa6bdaeaafc286cb064bb91edef97c632b6"
		"c1113d107fa93a0905098a105043c2f05397f702514439a08a9e5ddc196100721d45c8"
		"fc17d2ed659376f8a00bd5cb9a0860e26d8a29d8d6aaf52de97e9346033d6db501a35d"
		"bbaf97c20b830cd2d18c2532f3a59cc497ee64c0e57d8d060e5069b28d86edf1adcf59"
		"144b221ce3ddaef134b3124fbc7dd000240eff0f5f5f41e83cd7f5bb37c9ae21953fe3"
		"02b0f6e8b68fa91c6ab99265c64b2fd9cd4942be04321bb5d6d71932376c6f2f88e024"
		"22ba6a5e2cb765df93fd5dd0728c6abdaf03bce22e0678a544e2c3636f741b6f4447ee"
		"58a8fc656b43ef817932176adbfc2e04b2c812c273cd6cbfa4098f0be036a34221fa02"
		"643f5ee2e0b38135f2a18ecd2f16ebc45f8eb31b8ab967a1567ee016904188910861ca"
		"1fa205c7adaa194b286893ffe2f4fbe0384c2aef72a4522aeafd3ebc71f9db71eeeef8"
		"6c48394a1c86d5b36c352cc33a0a2c800bc99e62fd65b3a2fd69e0b53996ec13d8ce48"
		"3ce9319efd9a85acefabdb5342226febb83fd1daf4b24265f50c61c6de74077ef89b6f"
		"ecf9f29a1f871af1e9f89b2d345cda7499bd45c42fa5d195a1e1a6ba84851889e730da"
		"3b2b916e96152ae0c92154b49719841db7e7cc707ba8a5d7b101eb4ac7b629bb327817"
		"910fff61580b59aab78182d1a2e33473d05b00b170b29e331870826cfe45af206aa7d0"
		"246bbd8566ca7cfb2d3c10bfa1db7dd48dd786036469ce7282093d78b5e1a5b0fc81a5"
		"4c8ed4ceac1e5305305e78284ac276f5d7862727aff246e17addde50c670028d572cbf"
		"c0be2e4f8b2eb28fa68ad7b4c6c2a239c460441bfb5ea049f23b08563b4e47729a59e5"
		"986a61a6093dbd54f8c36ebe87edae01f251cb060ad1364ce677d7e8d5a4a4ca966a72"
		"41cc360bc2acb280e5f9e9c1b032ad6a180a35e0c5180b9d16d026c865b252098cc1d9"
		"9ba7375ca31c7702c0d943d5e3dd2f6861fa55bd46d94b67ed3e52eccd8dd06d968e01"
		"897d6de97ed3058d91dd",
	.p_expected_output =
		"8e4bc6f8b8c60fe4d68c61d9b159c8693c3151c46749af58da228442d927f23359bd6c"
		"cd6c2ec8fa3f00a86cecbfa728e1ad60b821ed22fcd309ba91a4138bc9"
};

/* SHA512 - NIST CAVS 11.0 */
ITEM_REGISTER(test_vector_hash_512_data,
	      test_vector_hash_t test_vector_sha512_4088) = {
	.digest_type = MBEDTLS_MD_SHA512,
	.expected_err_code = 0,
	.expected_result = EXPECTED_TO_PASS,
	.p_test_vector_name = TV_NAME("SHA512 message_len=4088"),
	.p_input =
		"c8e2e36403ad4ff9f60010cb877a57139ac1463a8522059cc377128dec4ed899e44784"
		"1053be14c356aab00875c53e04d4ee3129adcba1fdfdb2a11d7ecacd82d66d22040ed1"
		"131c45e8d8eea6840a8797bf6d63339a0d32fbe48cdbc85ebac2051c66471a2e748f2b"
		"80308603ffe2244bfda3f000d76ec324d57acfb351c7dfd81cf7e0611d60a1713b5fd7"
		"747eef6458707ad9fbcaef39df4c140025ed1e63b9347fdacae6ffdc7de10ee9e24858"
		"ce27e09b250bbab51b961302760778e4d60f2ea33a3cd078c7b83ae4c533a646eb1e15"
		"addc1af1ebf1b0f0eb39423b44be41d00d0aa124f4ea8a0d8a7251e0e141a6d659070f"
		"b5b74495ac7752bc7e64a5b9e36552e02b9ace5c24a7f8223e505a28ed47acd14f419a"
		"ac0f4fc85f896c12de2e5218e12a93fa9445e4609007bcbe0a201ed64a07b27e5fe01b"
		"a312a3858e187b7d668c6c06f69c39e9b182854cf3b638868a6124327515e982ebbc15"
		"d7a0cf908e43c9381c4bdac85df3dffe298392fd29d2fef0e80937f02da9472889d06b"
		"362cb880d5fc80b8b9e92f91bb7af60836acb509b1fdc12bbec4e59a21c3a65435ffcb"
		"998cd01d9cd6346c7f0468d27eadba3c6bb099255a1beea59d4bafabf355b086fca5bd"
		"abf0e5e7b291211ba15e28f96d0a35e2be2cce53f338ed7266ae5ee7f19168edb11baf"
		"a909af59baea0f701152cf8703130aa19cd6534e375fee174b13411c88b785fc237ac1"
		"f56e36f94dabf3a2f022ad5a5a7157d6b7241f1c4985f4f20bb5459694fc0caf3d5e0c"
		"84866f566cb6681285c2797ca970612d9ebc3d9c8d7b9de4b63eddc86179b3f418e504"
		"851322fcccf4a15d4fb5c11711de381a14fbb5681b4dc46eb4c0f194761d301388817c"
		"06630ebfc5d8e0f26e544285c46322013d73c3ec56dbb2ed2a1bfb3043659c0cb05d3a"
		"e3571e134a8d7d346ae491eca64473807f3e4220b49c6a1aad3d264e192044e2d7be29"
		"37129d141bb122a740eea7a3ec44cdf3f38f13ece36fa8d37eed7e9f6d61a0013293c5"
		"a25f2025ac051f8b8b7005acf511c6b727bc3d2d7214cef3f7434aa6afee122eae6780"
		"96a825821ab47288825064a1afa50ee0740df705a7d3cc59773a51daffc09d981ca387"
		"5f7ca55c96f80cd36724ee422124ab11dac1bb6f58bcaa45326160683260a613fed9e6"
		"94f7b63245623d88bec6e55549946937970d1c07b1617c17301409b8b1a65800847363"
		"caa4d823fdec976112877dc9d0a942405a7cb0776c5e07c0e249a1217a92d2a7dad712"
		"fdd5335e3deab3db060d0ebdcfab90677be858d32d2bc3355ddc28db2c6cc658f496fa"
		"e124e5b6f74b772e477200d4ceaf118740f79b07ab34afad57978759f230caabe9bc0c"
		"7619be9471a7d163302c3c725316c73afe4bcd79890f93347827d8f8ad3ead66dc8987"
		"ef40a793db8ccb4990251c44118e5c51c523c8c67a0b4015a968a8a0fbd08ecf0d010d"
		"6070d0f1fff5631b1727a028e718e54dd861fa850e6444ef3dd43b71be781ea2e22be5"
		"e7862877dce7841df5b8fc366572f12d3eecb1a9da2bf8037b7bb7fd2ebe13b1f505b1"
		"c7245d31eb0cecf87ed73c338cb3d618ff33136f12f12f5208799f311d62a419bdbe21"
		"35f4b5aa95266cdd2e002cf522aec09c424e1e01d1a54a2b8b11788de6bf71da981e37"
		"1a5994ecfeea6ff070561e4a6f78a1491abd3e6a0a2c767de5a33704306353dc65ce31"
		"1f4670c348703db7983319f2b9a19e3aa2e51932bad7d58c40cd9d7aeab37c65cc5ec7"
		"e27c1d5de274912e28b7bffa01b8645b2f77880626ed564e7baa2bea99bdedf7b6d49e"
		"4105a431be2d8b9c5bfb742efb53fc23bd6dd3767e3e64f6a033b89c0925971c6e8af1"
		"bad1e87d5f4890a0ec018890ce83c9b9d336aa603b269d861304190fbe6ed723d56f41"
		"d5314a28024573b57cb1dfa268157da9e523053deff9f07982adc7560229a120da39e8"
		"2b64e25bc209f65960a9e55c233cd6c47dbaf6d62d3910046d555f6e6dd5a0aa018c6a"
		"c0967cc2796b42ebdafeae7bebc4b1b4bd1c7c10aa86e61edf100e8d18124286ab1b20"
		"40c82bfbceff23813b02799ad8ad3093d543087b0ffbf2cd29bbc650de23383c95cd09"
		"9e36d37afd3d92063e0dae50c586575bddd9caf95a9b1a867d1930d517ec106bf1cd5f"
		"eb6caa22d265f9c9645b4c6ce7d425540efc0cbdb890e0dadbfa6b1ababe38aa5f14a9"
		"3b45d64405559d4e0c13289ba21afda42dc652da2a302d3a725fcb22bcbc3f6364c75b"
		"976b09d3b5be49a0e2bb03a38af1168bb027bdf882a0c0e0319eec33ff25c0ba9a0169"
		"45a80bf105a3a7b337e791120209da6aa36b2d47c70d57d538a60698bcf4d15d3b5079"
		"711f856f1000e29620818e4920751ca05b475fef61988090b7294de3cefcd49232b631"
		"1a0448a487aacee77ec5b7be816327cf6f7799b44a86c94f3da2d15dde9c924eb07655"
		"55ec17b2bb8142b27859c93004defe856bbd6b64a0e9c30213e4187a853a4d711b4ecf"
		"f5b25880ab73aff42aa744e0a2cc6fcfc1e8ef17d71d2c0c387ebe73e221333a5f750d"
		"66edd60b4cdd5faa043900ea1ba9d0558897a43ee192e047cff08d26c0b8aca8dbbfca"
		"f53910d51752912eb6b5e4ff25fd8ccfa3005154da49e588acc9c7ff2fc96877f6238d"
		"b193b2f47f59073a1f675dfcc7e2cf3d8181c907394fbd5514ac17310495721a9a260c"
		"a81b5d7773d5219230b383b81d104337a0c996042a9626ad629a5b8e8038d948f6294a"
		"6f56cb5d8370bc0e22baa8297bf65f09060e2ba6734360cfe08634b34e26d1a656aca9"
		"2218040a0c75ddf2397e5124312bc97b33511b7f79cef636bc06803dfb943d16793933"
		"c405184c957d26fb4095dc222fd52f341ee1c197e5fd594c92d091d1bb68ce46137f75"
		"d03afd5c3bdabe7fe3ef94f5d466902230ea7d2dd1fbaeb43040fabf851e04f33089c0"
		"09581a327ed262798b447f0d578aec456c589e1c67214c34f4380e1bfa3629ce139b29"
		"7b3fb8318bd9cc90e0ca6d945bfc29a3a2126e872056a70a4df2a8c32f644c2f212c5c"
		"04d3c7b3c192e1a08ac9c78c33c81bdd9bc5cb1a3b20434ffeece2b353aaab8881573e"
		"433caa06ed7597b3c97617eb372d2b3cd8c81e56f3830b7717bea02602532124c226b0"
		"a01afecbaa279316ea43e85b922adacf915cf9970ac2988a049320396379aa2c17f0cc"
		"6f93efb24e80cb715cb35899ba5d51099582fa08f1ad0391a5e1b0eda7d237888a556a"
		"fd451695733689aa2c67239b5b0fc908365c891a4d6f88af1aa93bb7d925dadd9a8512"
		"6b94f2fb67bc5e4902960cc6344b5300a0fd9f3ebd57b8b93768470993b196de137c97"
		"f0d97028394e639561c56f5e7a5c483bed23cc5eb481dcf8cad36bfee055d42d524671"
		"4c594769b18205c9065f17d74d7c2aa322945bde4005e4ef4782fb44bd08f7e65213b5"
		"5168113a82d2179951dcd317018cc28e1628a20f66f82bcb734dfa34f8c3ce5fc2c2f6"
		"adc14b0aaa5ff1da351025a4e22bb78a9cf89a428f0ae81045cf25f10e65c819a6aff7"
		"a012a99379cbf874a31ec6f6a3d3ccb4310db09332719203e68ae281636c74604298d6"
		"ca9820e102280c8eebd6fb0bce5f0e0e5848016ae2149be0f6ba49370e56068e9e1f7d"
		"f25599722ca00c5edc713459cc3e3a3d7e4ce309072d0883208846227b18f62a53f75f"
		"19471d2b42682318b8914df06df7c8bb9b00303363595678b5433f056f2d70e3c98868"
		"1cf0d76f73f1058e52d9fcdf041a73072431070056868e1c3594a8468c49968bc8b050"
		"daadcdd10849c9b617264f07b8c435550e465f05b56ce0eb03c1631b8e16cafbee2e14"
		"9dc4bb844cfb89ff654dfab76909b2064f14939c1f2eecddbc77ed8501325f8e10c892"
		"53e71096f535cdadfe6b790144154193116b5074802350372a8a2ea602d31eb47eafe0"
		"b3f81e41c75384e49be1ff425284f8f0c114f821db01bd6b6c3a8ece0b4dcbf249cfc8"
		"b02ffedbd4e8a5b421ba40ed963b61e2f0c152c3701afce8de7d0764cec143dc22cd47"
		"9ad05058dde6b28c73cb4a2e8ac7d165c4c516118958f4f6a1fd811c02a08975e6613b"
		"c1219721afb215564598adf381e7f3ca411a435760ab06f322e1304bd2ea0d11a9293e"
		"f1f2d1ffc76cb3ab0ff054819c5343a88e8ea9717e1c22ddfba4cb5f3ad89de2099df9"
		"0e056c83c70df834f7f611ab8e80c8c4c789d46cac8134b4dc1e16248c51f851cc780d"
		"b10bd5e2afde3f41fbfd1756248e7e1068a7c5cacb0e252b6643b14a02c08816e57f4f"
		"f6ecbddfacdafe3a7ff051c499bed5b0ae387cb8de0c0f11dd33729e51c62a647b141c"
		"3e1af197d18c5195c337153e282724ae3df8bef859f70d6b2084fd14fabb4e83c453e8"
		"d2c5c56ee4e3b115eb167eb72d1e42230771e1b83278783245fafcc37bd91e66b7fc72"
		"70c58cd167e363fc1880c181e44341e35b4f0cf50cc64d879a8be544134d5fdb7ec126"
		"5db32ef5e6702f9080a8b5b2441e4b46c3339ed9a4fc3c508e989cd648c15f191ea0d5"
		"b687e6c3f1061863aa4e2aad8da950d5889a111582c19dac4a006027cddcd7df8d26a3"
		"c34edadc571247a7fd48700b7441b3009ee3a8c986a14c84a1ab5f0054610aceb70ec5"
		"9b99d378bdc4e1e00b81eb35f25fdc0ac531c5745556196ec23d1c7c9027998ffd2fd3"
		"299288bfc1f90770690ee1d3ae38b59cc0facd80d3c5a1a5c4119c5700ac23fca251d4"
		"4adb7c0bb7977dab315dcb1b10779c8e4954b288e42a789eb0df4d7d352a202deaf63d"
		"97a80766455fdf266a08e36222daba31fac1f6eeb30cf68b43650a271d07d9e3b22b00"
		"f238c3fcf0aa6b4a75109dcce900246f9a65d30b0b7f768b902b094d176528cc490bc7"
		"7cd2e323f5fce0f85483a1f5dea53b6de778384ff380e0581a81b787b19246d226731e"
		"172c201b5518a6e61c8b36bd42527877d88a21c25c08c8b030f8f6724bc37c632f3709"
		"481be2fbd581be7674ba14b343f99a9b5b7ede95580ce89c169c1b94b8535ddeefb278"
		"2a790dbf8ce73ef4d3a49a69163324668fb801cbacba2cf664276be7c89882a2dad7a6"
		"d5a19f34bb7da2a340b9d0b8665fd7f8e750e6631c93b75f1deeccf32ab3f9354add22"
		"06315b46fc67acbca0a7acbdda86ae23a955ca70174779126dd75fe6a36467fa1a1e15"
		"978e26187f46f11f738deeeef86668b15b7cad90f3587083a6d66c68aeda4a539d3fc5"
		"259f100c6000fb6739ee021eef7f74975cf61cbeca42b8a907c7ad7dbc61f88bfaa668"
		"bf166c0a3bb78ce53f2de5e84c04a32189d9c130656dccfa7ef8eaa2c2c01cb5d3e9c0"
		"a4b08f5a78931293c115b182cf985b2b25e6c1452b16b04123b09e875e118303b010ea"
		"e021e14793e53a8b1c8fb5f68881762cbba70d8c6c659dbd71cd3e893d16a1efa749f3"
		"73ed3e03b9f8c7a652e12b5bd6b5d62b33754ed344616925a676beacc736598f3fa7b3"
		"b7649ee134183d0bdde6bb20374e63c8995ce09a8d80b790789915b77e53cb2ba0b397"
		"4327f0a509468555edfb843fba362d75c83dbf07744f8ecdcd8756609004cf6a574781"
		"200ddcda0ca53d7e100bf3dea85bfe0c6f5277cee50274f16fc92cdf9f835c74b6ffe9"
		"0e67b0c6e3dea5189801bb980ff6123980e5bd0ccbffbe600cbf312d706fc7b348ef76"
		"5e5cb26fed820951d36fa49cddcc5568168d1857e87e51c8831e544d83b12a60cc9193"
		"51b9c5478377d481d8abdbbe6a5bdec27c0b5cddb026266c7aa071a2",
	.p_expected_output =
		"e8e09fc57bd3b8e18b2726418836852cf1544eb2cf28c18f5b98436382d0b621953d2f"
		"aa60d155dd28c2cb76c00ee93d3de56289b399c22a4fd82f00dd35ef27"
};

ITEM_REGISTER(test_vector_hash_512_long_data,
	      test_vector_hash_t test_vector_sha512_long) = {
	.digest_type = MBEDTLS_MD_SHA512,
	.expected_err_code = 0,
	.expected_result = EXPECTED_TO_PASS,
	.mode = NO_MODE,
	.chunk_length = 4096,
	.update_iterations = 256,
	.p_test_vector_name = TV_NAME("SHA512 message_len=1048576"),
	.p_input = flash_data_sha_512,
	.p_expected_output =
		"4f544f809b8a0a7052eca55df04ba4b19c3ecd2dca6c721ab7e88d94574d663cbde4ca"
		"3dc114f92c827226184899c5c48c706b20d66cb056f97e0a21cf2979f5"
};

ITEM_REGISTER(test_vector_hash_512_long_data,
	      test_vector_hash_t test_vector_sha512_long_flash) = {
	.digest_type = MBEDTLS_MD_SHA512,
	.expected_err_code = 0,
	.expected_result = EXPECTED_TO_PASS,
	.mode = DO_MEMCPY,
	.chunk_length = 4096,
	.update_iterations = 256,
	.p_test_vector_name = TV_NAME("SHA512 flash memcpy message_len=1048576"),
	.p_input = flash_data_sha_512,
	.p_expected_output =
		"4f544f809b8a0a7052eca55df04ba4b19c3ecd2dca6c721ab7e88d94574d663cbde4ca"
		"3dc114f92c827226184899c5c48c706b20d66cb056f97e0a21cf2979f5"
};