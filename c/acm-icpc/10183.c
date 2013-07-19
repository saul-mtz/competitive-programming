/**********************************************************
	Program:    How many Fibs?
	Author:		Sa�l Mart�nez Vidals
	Date:		30-04-2007
***********************************************************
	@JUDGE_ID: 63787VV 10183 C "Dyamic programming"
	Link: 
***********************************************************
					SOLVED !!!
**********************************************************/

#include <stdio.h>
#include <string.h>

typedef struct fib
{
	short n;
	char numero[102];
} fibonacci;

fibonacci sucesion[] =
{
	1, "1",
	1, "2",
	1, "3",
	1, "5",
	1, "8",
	2, "13",
	2, "21",
	2, "34",
	2, "55",
	2, "89",
	3, "144",
	3, "233",
	3, "377",
	3, "610",
	3, "987",
	4, "1597",
	4, "2584",
	4, "4181",
	4, "6765",
	5, "10946",
	5, "17711",
	5, "28657",
	5, "46368",
	5, "75025",
	6, "121393",
	6, "196418",
	6, "317811",
	6, "514229",
	6, "832040",
	7, "1346269",
	7, "2178309",
	7, "3524578",
	7, "5702887",
	7, "9227465",
	8, "14930352",
	8, "24157817",
	8, "39088169",
	8, "63245986",
	9, "102334155",
	9, "165580141",
	9, "267914296",
	9, "433494437",
	9, "701408733",
	10, "1134903170",
	10, "1836311903",
	10, "2971215073",
	10, "4807526976",
	10, "7778742049",
	11, "12586269025",
	11, "20365011074",
	11, "32951280099",
	11, "53316291173",
	11, "86267571272",
	12, "139583862445",
	12, "225851433717",
	12, "365435296162",
	12, "591286729879",
	12, "956722026041",
	13, "1548008755920",
	13, "2504730781961",
	13, "4052739537881",
	13, "6557470319842",
	14, "10610209857723",
	14, "17167680177565",
	14, "27777890035288",
	14, "44945570212853",
	14, "72723460248141",
	15, "117669030460994",
	15, "190392490709135",
	15, "308061521170129",
	15, "498454011879264",
	15, "806515533049393",
	16, "1304969544928657",
	16, "2111485077978050",
	16, "3416454622906707",
	16, "5527939700884757",
	16, "8944394323791464",
	17, "14472334024676221",
	17, "23416728348467685",
	17, "37889062373143906",
	17, "61305790721611591",
	17, "99194853094755497",
	18, "160500643816367088",
	18, "259695496911122585",
	18, "420196140727489673",
	18, "679891637638612258",
	19, "1100087778366101931",
	19, "1779979416004714189",
	19, "2880067194370816120",
	19, "4660046610375530309",
	19, "7540113804746346429",
	20, "12200160415121876738",
	20, "19740274219868223167",
	20, "31940434634990099905",
	20, "51680708854858323072",
	20, "83621143489848422977",
	21, "135301852344706746049",
	21, "218922995834555169026",
	21, "354224848179261915075",
	21, "573147844013817084101",
	21, "927372692193078999176",
	22, "1500520536206896083277",
	22, "2427893228399975082453",
	22, "3928413764606871165730",
	22, "6356306993006846248183",
	23, "10284720757613717413913",
	23, "16641027750620563662096",
	23, "26925748508234281076009",
	23, "43566776258854844738105",
	23, "70492524767089125814114",
	24, "114059301025943970552219",
	24, "184551825793033096366333",
	24, "298611126818977066918552",
	24, "483162952612010163284885",
	24, "781774079430987230203437",
	25, "1264937032042997393488322",
	25, "2046711111473984623691759",
	25, "3311648143516982017180081",
	25, "5358359254990966640871840",
	25, "8670007398507948658051921",
	26, "14028366653498915298923761",
	26, "22698374052006863956975682",
	26, "36726740705505779255899443",
	26, "59425114757512643212875125",
	26, "96151855463018422468774568",
	27, "155576970220531065681649693",
	27, "251728825683549488150424261",
	27, "407305795904080553832073954",
	27, "659034621587630041982498215",
	28, "1066340417491710595814572169",
	28, "1725375039079340637797070384",
	28, "2791715456571051233611642553",
	28, "4517090495650391871408712937",
	28, "7308805952221443105020355490",
	29, "11825896447871834976429068427",
	29, "19134702400093278081449423917",
	29, "30960598847965113057878492344",
	29, "50095301248058391139327916261",
	29, "81055900096023504197206408605",
	30, "131151201344081895336534324866",
	30, "212207101440105399533740733471",
	30, "343358302784187294870275058337",
	30, "555565404224292694404015791808",
	30, "898923707008479989274290850145",
	31, "1454489111232772683678306641953",
	31, "2353412818241252672952597492098",
	31, "3807901929474025356630904134051",
	31, "6161314747715278029583501626149",
	31, "9969216677189303386214405760200",
	32, "16130531424904581415797907386349",
	32, "26099748102093884802012313146549",
	32, "42230279526998466217810220532898",
	32, "68330027629092351019822533679447",
	33, "110560307156090817237632754212345",
	33, "178890334785183168257455287891792",
	33, "289450641941273985495088042104137",
	33, "468340976726457153752543329995929",
	33, "757791618667731139247631372100066",
	34, "1226132595394188293000174702095995",
	34, "1983924214061919432247806074196061",
	34, "3210056809456107725247980776292056",
	34, "5193981023518027157495786850488117",
	34, "8404037832974134882743767626780173",
	35, "13598018856492162040239554477268290",
	35, "22002056689466296922983322104048463",
	35, "35600075545958458963222876581316753",
	35, "57602132235424755886206198685365216",
	35, "93202207781383214849429075266681969",
	36, "150804340016807970735635273952047185",
	36, "244006547798191185585064349218729154",
	36, "394810887814999156320699623170776339",
	36, "638817435613190341905763972389505493",
	37, "1033628323428189498226463595560281832",
	37, "1672445759041379840132227567949787325",
	37, "2706074082469569338358691163510069157",
	37, "4378519841510949178490918731459856482",
	37, "7084593923980518516849609894969925639",
	38, "11463113765491467695340528626429782121",
	38, "18547707689471986212190138521399707760",
	38, "30010821454963453907530667147829489881",
	38, "48558529144435440119720805669229197641",
	38, "78569350599398894027251472817058687522",
	39, "127127879743834334146972278486287885163",
	39, "205697230343233228174223751303346572685",
	39, "332825110087067562321196029789634457848",
	39, "538522340430300790495419781092981030533",
	39, "871347450517368352816615810882615488381",
	40, "1409869790947669143312035591975596518914",
	40, "2281217241465037496128651402858212007295",
	40, "3691087032412706639440686994833808526209",
	40, "5972304273877744135569338397692020533504",
	40, "9663391306290450775010025392525829059713",
	41, "15635695580168194910579363790217849593217",
	41, "25299086886458645685589389182743678652930",
	41, "40934782466626840596168752972961528246147",
	41, "66233869353085486281758142155705206899077",
	42, "107168651819712326877926895128666735145224",
	42, "173402521172797813159685037284371942044301",
	42, "280571172992510140037611932413038677189525",
	42, "453973694165307953197296969697410619233826",
	42, "734544867157818093234908902110449296423351",
	43, "1188518561323126046432205871807859915657177",
	43, "1923063428480944139667114773918309212080528",
	43, "3111581989804070186099320645726169127737705",
	43, "5034645418285014325766435419644478339818233",
	43, "8146227408089084511865756065370647467555938",
	44, "13180872826374098837632191485015125807374171",
	44, "21327100234463183349497947550385773274930109",
	44, "34507973060837282187130139035400899082304280",
	44, "55835073295300465536628086585786672357234389",
	44, "90343046356137747723758225621187571439538669",
	45, "146178119651438213260386312206974243796773058",
	45, "236521166007575960984144537828161815236311727",
	45, "382699285659014174244530850035136059033084785",
	45, "619220451666590135228675387863297874269396512",
	46, "1001919737325604309473206237898433933302481297",
	46, "1621140188992194444701881625761731807571877809",
	46, "2623059926317798754175087863660165740874359106",
	46, "4244200115309993198876969489421897548446236915",
	46, "6867260041627791953052057353082063289320596021",
	47, "11111460156937785151929026842503960837766832936",
	47, "17978720198565577104981084195586024127087428957",
	47, "29090180355503362256910111038089984964854261893",
	47, "47068900554068939361891195233676009091941690850",
	47, "76159080909572301618801306271765994056795952743",
	48, "123227981463641240980692501505442003148737643593",
	48, "199387062373213542599493807777207997205533596336",
	48, "322615043836854783580186309282650000354271239929",
	48, "522002106210068326179680117059857997559804836265",
	48, "844617150046923109759866426342507997914076076194",
	49, "1366619256256991435939546543402365995473880912459",
	49, "2211236406303914545699412969744873993387956988653",
	49, "3577855662560905981638959513147239988861837901112",
	49, "5789092068864820527338372482892113982249794889765",
	49, "9366947731425726508977331996039353971111632790877",
	50, "15156039800290547036315704478931467953361427680642",
	50, "24522987531716273545293036474970821924473060471519",
	50, "39679027332006820581608740953902289877834488152161",
	50, "64202014863723094126901777428873111802307548623680",
	51, "103881042195729914708510518382775401680142036775841",
	51, "168083057059453008835412295811648513482449585399521",
	51, "271964099255182923543922814194423915162591622175362",
	51, "440047156314635932379335110006072428645041207574883",
	51, "712011255569818855923257924200496343807632829750245",
	52, "1152058411884454788302593034206568772452674037325128",
	52, "1864069667454273644225850958407065116260306867075373",
	52, "3016128079338728432528443992613633888712980904400501",
	52, "4880197746793002076754294951020699004973287771475874",
	52, "7896325826131730509282738943634332893686268675876375",
	53, "12776523572924732586037033894655031898659556447352249",
	53, "20672849399056463095319772838289364792345825123228624",
	53, "33449372971981195681356806732944396691005381570580873",
	53, "54122222371037658776676579571233761483351206693809497",
	53, "87571595343018854458033386304178158174356588264390370",
	54, "141693817714056513234709965875411919657707794958199867",
	54, "229265413057075367692743352179590077832064383222590237",
	54, "370959230771131880927453318055001997489772178180790104",
	54, "600224643828207248620196670234592075321836561403380341",
	54, "971183874599339129547649988289594072811608739584170445",
	55, "1571408518427546378167846658524186148133445300987550786",
	55, "2542592393026885507715496646813780220945054040571721231",
	55, "4114000911454431885883343305337966369078499341559272017",
	55, "6656593304481317393598839952151746590023553382130993248",
	56, "10770594215935749279482183257489712959102052723690265265",
	56, "17427187520417066673081023209641459549125606105821258513",
	56, "28197781736352815952563206467131172508227658829511523778",
	56, "45624969256769882625644229676772632057353264935332782291",
	56, "73822750993122698578207436143903804565580923764844306069",
	57, "119447720249892581203851665820676436622934188700177088360",
	57, "193270471243015279782059101964580241188515112465021394429",
	57, "312718191492907860985910767785256677811449301165198482789",
	57, "505988662735923140767969869749836918999964413630219877218",
	57, "818706854228831001753880637535093596811413714795418360007",
	58, "1324695516964754142521850507284930515811378128425638237225",
	58, "2143402371193585144275731144820024112622791843221056597232",
	58, "3468097888158339286797581652104954628434169971646694834457",
	58, "5611500259351924431073312796924978741056961814867751431689",
	58, "9079598147510263717870894449029933369491131786514446266146",
	59, "14691098406862188148944207245954912110548093601382197697835",
	59, "23770696554372451866815101694984845480039225387896643963981",
	59, "38461794961234640015759308940939757590587318989278841661816",
	59, "62232491515607091882574410635924603070626544377175485625797",
	60, "100694286476841731898333719576864360661213863366454327287613",
	60, "162926777992448823780908130212788963731840407743629812913410",
	60, "263621064469290555679241849789653324393054271110084140201023",
	60, "426547842461739379460149980002442288124894678853713953114433",
	60, "690168906931029935139391829792095612517948949963798093315456",
	61, "1116716749392769314599541809794537900642843628817512046429889",
	61, "1806885656323799249738933639586633513160792578781310139745345",
	61, "2923602405716568564338475449381171413803636207598822186175234",
	61, "4730488062040367814077409088967804926964428786380132325920579",
	61, "7654090467756936378415884538348976340768064993978954512095813",
	62, "12384578529797304192493293627316781267732493780359086838016392",
	62, "20038668997554240570909178165665757608500558774338041350112205",
	62, "32423247527351544763402471792982538876233052554697128188128597",
	62, "52461916524905785334311649958648296484733611329035169538240802",
	62, "84885164052257330097714121751630835360966663883732297726369399",
	63, "137347080577163115432025771710279131845700275212767467264610201",
	63, "222232244629420445529739893461909967206666939096499764990979600",
	63, "359579325206583560961765665172189099052367214309267232255589801",
	63, "581811569836004006491505558634099066259034153405766997246569401",
	63, "941390895042587567453271223806288165311401367715034229502159202",
	64, "1523202464878591573944776782440387231570435521120801226748728603",
	64, "2464593359921179141398048006246675396881836888835835456250887805",
	64, "3987795824799770715342824788687062628452272409956636682999616408",
	64, "6452389184720949856740872794933738025334109298792472139250504213",
	65, "10440185009520720572083697583620800653786381708749108822250120621",
	65, "16892574194241670428824570378554538679120491007541580961500624834",
	65, "27332759203762391000908267962175339332906872716290689783750745455",
	65, "44225333398004061429732838340729878012027363723832270745251370289",
	65, "71558092601766452430641106302905217344934236440122960529002115744",
	66, "115783425999770513860373944643635095356961600163955231274253486033",
	66, "187341518601536966291015050946540312701895836604078191803255601777",
	66, "303124944601307480151388995590175408058857436768033423077509087810",
	66, "490466463202844446442404046536715720760753273372111614880764689587",
	66, "793591407804151926593793042126891128819610710140145037958273777397",
	67, "1284057871006996373036197088663606849580363983512256652839038466984",
	67, "2077649278811148299629990130790497978399974693652401690797312244381",
	67, "3361707149818144672666187219454104827980338677164658343636350711365",
	67, "5439356428629292972296177350244602806380313370817060034433662955746",
	67, "8801063578447437644962364569698707634360652047981718378070013667111",
	68, "14240420007076730617258541919943310440740965418798778412503676622857",
	68, "23041483585524168262220906489642018075101617466780496790573690289968",
	68, "37281903592600898879479448409585328515842582885579275203077366912825",
	68, "60323387178125067141700354899227346590944200352359771993651057202793",
	68, "97605290770725966021179803308812675106786783237939047196728424115618",
	69, "157928677948851033162880158208040021697730983590298819190379481318411",
	69, "255533968719576999184059961516852696804517766828237866387107905434029",
	69, "413462646668428032346940119724892718502248750418536685577487386752440",
	69, "668996615388005031531000081241745415306766517246774551964595292186469",
	70, "1082459262056433063877940200966638133809015267665311237542082678938909",
	70, "1751455877444438095408940282208383549115781784912085789506677971125378",
	70, "2833915139500871159286880483175021682924797052577397027048760650064287",
	70, "4585371016945309254695820765383405232040578837489482816555438621189665",
	70, "7419286156446180413982701248558426914965375890066879843604199271253952",
	71, "12004657173391489668678522013941832147005954727556362660159637892443617",
	71, "19423943329837670082661223262500259061971330617623242503763837163697569",
	71, "31428600503229159751339745276442091208977285345179605163923475056141186",
	71, "50852543833066829834000968538942350270948615962802847667687312219838755",
	71, "82281144336295989585340713815384441479925901307982452831610787275979941",
	72, "133133688169362819419341682354326791750874517270785300499298099495818696",
	72, "215414832505658809004682396169711233230800418578767753330908886771798637",
	72, "348548520675021628424024078524038024981674935849553053830206986267617333",
	72, "563963353180680437428706474693749258212475354428320807161115873039415970",
	72, "912511873855702065852730553217787283194150290277873860991322859307033303",
	73, "1476475227036382503281437027911536541406625644706194668152438732346449273",
	73, "2388987100892084569134167581129323824600775934984068529143761591653482576",
	73, "3865462327928467072415604609040860366007401579690263197296200323999931849",
	73, "6254449428820551641549772190170184190608177514674331726439961915653414425",
	74, "10119911756749018713965376799211044556615579094364594923736162239653346274",
	74, "16374361185569570355515148989381228747223756609038926650176124155306760699",
	74, "26494272942318589069480525788592273303839335703403521573912286394960106973",
	74, "42868634127888159424995674777973502051063092312442448224088410550266867672",
	74, "69362907070206748494476200566565775354902428015845969798000696945226974645",
	75, "112231541198094907919471875344539277405965520328288418022089107495493842317",
	75, "181594448268301656413948075911105052760867948344134387820089804440720816962",
	75, "293825989466396564333419951255644330166833468672422805842178911936214659279",
	75, "475420437734698220747368027166749382927701417016557193662268716376935476241",
	75, "769246427201094785080787978422393713094534885688979999504447628313150135520",
	76, "1244666864935793005828156005589143096022236302705537193166716344690085611761",
	76, "2013913292136887790908943984011536809116771188394517192671163973003235747281",
	76, "3258580157072680796737099989600679905139007491100054385837880317693321359042",
	76, "5272493449209568587646043973612216714255778679494571578509044290696557106323",
	76, "8531073606282249384383143963212896619394786170594625964346924608389878465365",
	77, "13803567055491817972029187936825113333650564850089197542855968899086435571688",
	77, "22334640661774067356412331900038009953045351020683823507202893507476314037053",
	77, "36138207717265885328441519836863123286695915870773021050058862406562749608741",
	77, "58472848379039952684853851736901133239741266891456844557261755914039063645794",
	77, "94611056096305838013295371573764256526437182762229865607320618320601813254535",
	78, "153083904475345790698149223310665389766178449653686710164582374234640876900329",
	78, "247694960571651628711444594884429646292615632415916575771902992555242690154864",
	78, "400778865046997419409593818195095036058794082069603285936485366789883567055193",
	78, "648473825618649048121038413079524682351409714485519861708388359345126257210057",
	79, "1049252690665646467530632231274619718410203796555123147644873726135009824265250",
	79, "1697726516284295515651670644354144400761613511040643009353262085480136081475307",
	79, "2746979206949941983182302875628764119171817307595766156998135811615145905740557",
	79, "4444705723234237498833973519982908519933430818636409166351397897095281987215864",
	79, "7191684930184179482016276395611672639105248126232175323349533708710427892956421",
	80, "11636390653418416980850249915594581159038678944868584489700931605805709880172285",
	80, "18828075583602596462866526311206253798143927071100759813050465314516137773128706",
	80, "30464466237021013443716776226800834957182606015969344302751396920321847653300991",
	80, "49292541820623609906583302538007088755326533087070104115801862234837985426429697",
	80, "79757008057644623350300078764807923712509139103039448418553259155159833079730688",
	81, "129049549878268233256883381302815012467835672190109552534355121389997818506160385",
	81, "208806557935912856607183460067622936180344811293149000952908380545157651585891073",
	81, "337856107814181089864066841370437948648180483483258553487263501935155470092051458",
	81, "546662665750093946471250301438060884828525294776407554440171882480313121677942531",
	81, "884518773564275036335317142808498833476705778259666107927435384415468591769993989",
	82, "1431181439314368982806567444246559718305231073036073662367607266895781713447936520",
	82, "2315700212878644019141884587055058551781936851295739770295042651311250305217930509",
	82, "3746881652193013001948452031301618270087167924331813432662649918207032018665867029",
	82, "6062581865071657021090336618356676821869104775627553202957692569518282323883797538",
	82, "9809463517264670023038788649658295091956272699959366635620342487725314342549664567",
	83, "15872045382336327044129125268014971913825377475586919838578035057243596666433462105",
	83, "25681508899600997067167913917673267005781650175546286474198377544968911008983126672",
	83, "41553554281937324111297039185688238919607027651133206312776412602212507675416588777",
	83, "67235063181538321178464953103361505925388677826679492786974790147181418684399715449",
	84, "108788617463475645289761992289049744844995705477812699099751202749393926359816304226",
	84, "176023680645013966468226945392411250770384383304492191886725992896575345044216019675",
	84, "284812298108489611757988937681460995615380088782304890986477195645969271404032323901",
	84, "460835978753503578226215883073872246385764472086797082873203188542544616448248343576",
	84, "745648276861993189984204820755333242001144560869101973859680384188513887852280667477",
	85, "1206484255615496768210420703829205488386909032955899056732883572731058504300529011053",
	85, "1952132532477489958194625524584538730388053593825001030592563956919572392152809678530",
	85, "3158616788092986726405046228413744218774962626780900087325447529650630896453338689583",
	85, "5110749320570476684599671752998282949163016220605901117918011486570203288606148368113",
	85, "8269366108663463411004717981412027167937978847386801205243459016220834185059487057696",
	86, "13380115429233940095604389734410310117100995067992702323161470502791037473665635425809",
	86, "21649481537897403506609107715822337285038973915379503528404929519011871658725122483505",
	86, "35029596967131343602213497450232647402139968983372205851566400021802909132390757909314",
	86, "56679078505028747108822605166054984687178942898751709379971329540814780791115880392819",
	86, "91708675472160090711036102616287632089318911882123915231537729562617689923506638302133",
	87, "148387753977188837819858707782342616776497854780875624611509059103432470714622518694952",
	87, "240096429449348928530894810398630248865816766662999539843046788666050160638129156997085",
	87, "388484183426537766350753518180972865642314621443875164454555847769482631352751675692037",
	87, "628580612875886694881648328579603114508131388106874704297602636435532791990880832689122",
	88, "1017064796302424461232401846760575980150446009550749868752158484205015423343632508381159",
	88, "1645645409178311156114050175340179094658577397657624573049761120640548215334513341070281",
	88, "2662710205480735617346452022100755074809023407208374441801919604845563638678145849451440",
	88, "4308355614659046773460502197440934169467600804865999014851680725486111854012659190521721",
	88, "6971065820139782390806954219541689244276624212074373456653600330331675492690805039973161",
	89, "11279421434798829164267456416982623413744225016940372471505281055817787346703464230494882",
	89, "18250487254938611555074410636524312658020849229014745928158881386149462839394269270468043",
	89, "29529908689737440719341867053506936071765074245955118399664162441967250186097733500962925",
	89, "47780395944676052274416277690031248729785923474969864327823043828116713025492002771430968",
	89, "77310304634413492993758144743538184801550997720924982727487206270083963211589736272393893",
	90, "125090700579089545268174422433569433531336921195894847055310250098200676237081739043824861",
	90, "202401005213503038261932567177107618332887918916819829782797456368284639448671475316218754",
	90, "327491705792592583530106989610677051864224840112714676838107706466485315685753214360043615",
	90, "529892711006095621792039556787784670197112759029534506620905162834769955134424689676262369",
	90, "857384416798688205322146546398461722061337599142249183459012869301255270820177904036305984",
	91, "1387277127804783827114186103186246392258450358171783690079918032136025225954602593712568353",
	91, "2244661544603472032436332649584708114319787957314032873538930901437280496774780497748874337",
	91, "3631938672408255859550518752770954506578238315485816563618848933573305722729383091461442690",
	91, "5876600217011727891986851402355662620898026272799849437157779835010586219504163589210317027",
	91, "9508538889419983751537370155126617127476264588285666000776628768583891942233546680671759717",
	92, "15385139106431711643524221557482279748374290861085515437934408603594478161737710269882076744",
	92, "24893677995851695395061591712608896875850555449371181438711037372178370103971256950553836461",
	92, "40278817102283407038585813270091176624224846310456696876645445975772848265708967220435913205",
	92, "65172495098135102433647404982700073500075401759827878315356483347951218369680224170989749666",
	93, "105451312200418509472233218252791250124300248070284575192001929323724066635389191391425662871",
	93, "170623807298553611905880623235491323624375649830112453507358412671675285005069415562415412537",
	93, "276075119498972121378113841488282573748675897900397028699360341995399351640458606953841075408",
	93, "446698926797525733283994464723773897373051547730509482206718754667074636645528022516256487945",
	93, "722774046296497854662108306212056471121727445630906510906079096662473988285986629470097563353",
	94, "1169472973094023587946102770935830368494778993361415993112797851329548624931514651986354051298",
	94, "1892247019390521442608211077147886839616506438992322504018876947992022613217501281456451614651",
	94, "3061719992484545030554313848083717208111285432353738497131674799321571238149015933442805665949",
	94, "4953967011875066473162524925231604047727791871346061001150551747313593851366517214899257280600",
	94, "8015687004359611503716838773315321255839077303699799498282226546635165089515533148342062946549",
	95, "12969654016234677976879363698546925303566869175045860499432778293948758940882050363241320227149",
	95, "20985341020594289480596202471862246559405946478745659997715004840583924030397583511583383173698",
	95, "33954995036828967457475566170409171862972815653791520497147783134532682971279633874824703400847",
	95, "54940336057423256938071768642271418422378762132537180494862787975116607001677217386408086574545",
	95, "88895331094252224395547334812680590285351577786328700992010571109649289972956851261232789975392",
	96, "143835667151675481333619103454952008707730339918865881486873359084765896974634068647640876549937",
	96, "232730998245927705729166438267632598993081917705194582478883930194415186947590919908873666525329",
	96, "376566665397603187062785541722584607700812257624060463965757289279181083922224988556514543075266",
	96, "609297663643530892791951979990217206693894175329255046444641219473596270869815908465388209600595",
	96, "985864329041134079854737521712801814394706432953315510410398508752777354792040897021902752675861",
	97, "1595161992684664972646689501703019021088600608282570556855039728226373625661856805487290962276456",
	97, "2581026321725799052501427023415820835483307041235886067265438236979150980453897702509193714952317",
	97, "4176188314410464025148116525118839856571907649518456624120477965205524606115754507996484677228773",
	97, "6757214636136263077649543548534660692055214690754342691385916202184675586569652210505678392181090",
	98, "10933402950546727102797660073653500548627122340272799315506394167390200192685406718502163069409863",
	98, "17690617586682990180447203622188161240682337031027142006892310369574875779255058929007841461590953",
	98, "28624020537229717283244863695841661789309459371299941322398704536965075971940465647510004531000816",
	98, "46314638123912707463692067318029823029991796402327083329291014906539951751195524576517845992591769",
	98, "74938658661142424746936931013871484819301255773627024651689719443505027723135990224027850523592585",
	99, "121253296785055132210628998331901307849293052175954107980980734350044979474331514800545696516184354",
	99, "196191955446197556957565929345772792668594307949581132632670453793550007197467505024573547039776939",
	99, "317445252231252689168194927677674100517887360125535240613651188143594986671799019825119243555961293",
	99, "513637207677450246125760857023446893186481668075116373246321641937144993869266524849692790595738232",
	99, "831082459908702935293955784701120993704369028200651613859972830080739980541065544674812034151699525",
	100, "1344719667586153181419716641724567886890850696275767987106294472017884974410332069524504824747437757",
	100, "2175802127494856116713672426425688880595219724476419600966267302098624954951397614199316858899137282",
	100, "3520521795081009298133389068150256767486070420752187588072561774116509929361729683723821683646575039",
	100, "5696323922575865414847061494575945648081290145228607189038829076215134884313127297923138542545712321",
	100, "9216845717656874712980450562726202415567360565980794777111390850331644813674856981646960226192287360",
	101, "14913169640232740127827512057302148063648650711209401966150219926546779697987984279570098768737999681",
};

int main()
{
	int i, la, lb, count;
	char a[102], b[102];
	
	scanf("%s %s", a, b);
	while((strcmp(a, "0") != 0) || (strcmp(b, "0") != 0)) {
		count = 0;
		i = -1;
		la = strlen(a);
		lb = strlen(b);
		while(sucesion[++i].n < la);
		i--;
		while((strcmp(sucesion[++i].numero, a) < 0) && (sucesion[i].n == la));
		i--;
		while(sucesion[++i].n < lb)
			count ++;
		i--;
		while((strcmp(sucesion[++i].numero, b) < 0) && (sucesion[i].n == lb))
			count ++;
		if(strcmp(sucesion[i].numero, b) == 0)
			count ++;
		printf("%d\n", count);
		scanf("%s %s", a, b);
	}

	return 0;
}
