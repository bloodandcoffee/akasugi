#ifndef KANA_H
#define KANA_H
#include <string>

struct Kana {
    std::string hiragana;
    std::string katakana;
};

struct Mapping {
    std::string romaji;
    const Kana* kana;
};

const Kana standard[] = {
    {"あ", "ア"},
    {"い", "イ"},
    {"う", "ウ"},
    {"え", "エ"},
    {"お", "オ"},

    {"か", "カ"},
    {"き", "キ"},
    {"く", "ク"},
    {"け", "ケ"},
    {"こ", "コ"},
    
    {"さ", "サ"},
    {"し", "シ"},
    {"す", "ス"},
    {"せ", "セ"},
    {"そ", "ソ"},

    {"た", "タ"},
    {"ち", "チ"},
    {"つ", "ツ"},
    {"て", "テ"},
    {"と", "ト"},

    {"な", "ナ"},
    {"に", "ニ"},
    {"ぬ", "ヌ"},
    {"ね", "ネ"},
    {"の", "ノ"},

    {"は", "ハ"},
    {"ひ", "ヒ"},
    {"ふ", "フ"},
    {"へ", "ヘ"},
    {"ほ", "ホ"},

    {"ま", "マ"},
    {"み", "ミ"},
    {"む", "ム"},
    {"め", "メ"},
    {"も", "モ"},

    {"や", "ヤ"},
    {"ゆ", "ユ"},
    {"よ", "ヨ"},

    {"ら", "ラ"},
    {"り", "リ"},
    {"る", "ル"},
    {"れ", "レ"},
    {"ろ", "ロ"},

    {"わ", "ワ"},
    {"ゐ", "ヰ"},
    {"ゑ", "ヱ"},
    {"を", "ヲ"},

    {"ん", "ン"}
};

const Kana dakuon[] = {
    {"が", "ガ"},
    {"ぎ", "ギ"},
    {"ぐ", "グ"},
    {"げ", "ゲ"},
    {"ご", "ゴ"},

    {"ざ", "ザ"},
    {"じ", "ジ"},
    {"ず", "ズ"},
    {"ぜ", "ゼ"},
    {"ぞ", "ゾ"},

    {"だ", "ダ"},
    {"ぢ", "ヂ"},
    {"づ", "ヅ"},
    {"で", "デ"},
    {"ど", "ド"},

    {"ば", "バ"},
    {"び", "ビ"},
    {"ぶ", "ブ"},
    {"べ", "ベ"},
    {"ぼ", "ボ"},
    
    {"ぱ", "パ"},
    {"ぴ", "ピ"},
    {"ぷ", "プ"},
    {"ぺ", "ペ"},
    {"ぽ", "ポ"}
};

const Kana youon[] = {
    {"きゃ", "キャ"},
    {"きゅ", "キュ"},
    {"きょ", "キョ"},

    {"しゃ", "シャ"},
    {"しゅ", "シュ"},
    {"しょ", "ショ"},

    {"ちゃ", "チャ"},
    {"ちゅ", "チュ"},
    {"ちょ", "チョ"},

    {"にゃ", "ニャ"},
    {"にゅ", "ニュ"},
    {"にょ", "ニョ"},

    {"ひゃ", "ヒャ"},
    {"ひゅ", "ヒュ"},
    {"ひょ", "ヒョ"},

    {"みゃ", "ミャ"},
    {"みゅ", "ミュ"},
    {"みょ", "ミョ"},

    {"りゃ", "リャ"},
    {"りゅ", "リュ"},
    {"りょ", "リョ"},

    {"ぎゃ", "ギャ"},
    {"ぎゅ", "ギュ"},
    {"ぎょ", "ギョ"},

    {"じゃ", "ジャ"},
    {"じゅ", "ジュ"},
    {"じょ", "ジョ"},

    {"びゃ", "ビャ"},
    {"びゅ", "ビュ"},
    {"びょ", "ビョ"},

    {"ぴゃ", "ピャ"},
    {"ぴゅ", "ピュ"},
    {"ぴょ", "ピュ"}
};

const Kana combination[] = {
    {"ふぁ", "ファ"},
    {"ゔぁ", "ヴァ"},
    {"つぁ", "ツァ"},

    {"ふぃ", "フィ"},
    {"ゔぃ", "ヴィ"},
    {"つぃ", "ツィ"},
    {"すぃ", "スィ"},
    {"ずぃ", "ズィ"},
    {"てぃ", "ティ"},
    {"でぃ", "ディ"},

    {"てぅ", "テゥ"},
    {"でぅ", "デゥ"},

    {"ふぇ", "フェ"},
    {"ゔぇ", "ヴェ"},
    {"しぇ", "シェ"},
    {"じぇ", "ジェ"},
    {"ちぇ", "チェ"},
    {"つぇ", "ツェ"},

    {"ふぉ", "フォ"},
    {"ゔぉ", "ヴォ"},
    {"つぉ", "ツォ"},

    {"くゎ", "クヮ"},
    {"くぃ", "クィ"},
    {"くぇ", "クェ"},
    {"ぐゎ", "グヮ"},
    {"ぐぃ", "グィ"},
    {"ぐぇ", "グェ"}
};

const Kana chiisai[] = {
    {"ぁ", "ァ"},
    {"ぃ", "ィ"},
    {"ぅ", "ゥ"},
    {"ぇ", "ェ"},
    {"ぉ", "ォ"},
    {"ゎ", "ヮ"},
    {"っ", "ッ"},
    {"ゕ", "ヵ"},
    {"ゖ", "ヶ"}
};

const Mapping kana[] = {
    // Normal Kana
    {"a", &standard[0]},
    {"i", &standard[1]},
    {"u", &standard[2]},
    {"e", &standard[3]},
    {"o", &standard[4]},

    {"ka", &standard[5]},
    {"ki", &standard[6]},
    {"ku", &standard[7]},
    {"ke", &standard[8]},
    {"ko", &standard[9]},

    {"sa", &standard[10]},
    {"shi", &standard[11]},
    {"su", &standard[12]},
    {"se", &standard[13]},
    {"so", &standard[14]},

    {"ta", &standard[15]},
    {"chi", &standard[16]},
    {"tsu", &standard[17]},
    {"te", &standard[18]},
    {"to", &standard[19]},

    {"na", &standard[20]},
    {"ni", &standard[21]},
    {"nu", &standard[22]},
    {"ne", &standard[23]},
    {"no", &standard[24]},

    {"ha", &standard[25]},
    {"hi", &standard[26]},
    {"fu", &standard[27]},
    {"he", &standard[28]},
    {"ho", &standard[29]},

    {"ma", &standard[30]},
    {"mi", &standard[31]},
    {"mu", &standard[32]},
    {"me", &standard[33]},
    {"mo", &standard[34]},

    {"ya", &standard[35]},
    {"yu", &standard[36]},
    {"yo", &standard[37]},

    {"ra", &standard[38]},
    {"ri", &standard[39]},
    {"ru", &standard[40]},
    {"re", &standard[41]},
    {"ro", &standard[42]},

    {"wa", &standard[43]},
    {"wi", &standard[44]},
    {"we", &standard[45]},
    {"wo", &standard[46]},

    {"n", &standard[47]},
    {"nn", &standard[47]},

    // Dakuon / Handakuon
    {"ga", &dakuon[0]},
    {"gi", &dakuon[1]},
    {"gu", &dakuon[2]},
    {"ge", &dakuon[3]},
    {"go", &dakuon[4]},

    {"za", &dakuon[5]},
    {"ji", &dakuon[6]},
    {"zu", &dakuon[7]},
    {"ze", &dakuon[8]},
    {"zo", &dakuon[9]},

    {"da", &dakuon[10]},
    {"di", &dakuon[11]},
    {"dzu", &dakuon[12]},
    {"de", &dakuon[13]},
    {"do", &dakuon[14]},

    {"ba", &dakuon[15]},
    {"bi", &dakuon[16]},
    {"bu", &dakuon[17]},
    {"be", &dakuon[18]},
    {"bo", &dakuon[19]},

    {"pa", &dakuon[20]},
    {"pi", &dakuon[21]},
    {"pu", &dakuon[22]},
    {"pe", &dakuon[23]},
    {"po", &dakuon[24]},

    // Youon
    {"kya", &youon[0]},
    {"kyu", &youon[1]},
    {"kyo", &youon[2]},

    {"sha", &youon[3]},
    {"shu", &youon[4]},
    {"sho", &youon[5]},

    {"cha", &youon[6]},
    {"chu", &youon[7]},
    {"cho", &youon[8]},

    {"nya", &youon[9]},
    {"nyu", &youon[10]},
    {"nyo", &youon[11]},

    {"hya", &youon[12]},
    {"hyu", &youon[13]},
    {"hyo", &youon[14]},

    {"mya", &youon[15]},
    {"myu", &youon[16]},
    {"myo", &youon[17]},

    {"rya", &youon[18]},
    {"ryu", &youon[19]},
    {"ryo", &youon[20]},

    {"gya", &youon[21]},
    {"gyu", &youon[22]},
    {"gyo", &youon[23]},

    {"ja", &youon[24]},
    {"ju", &youon[25]},
    {"jo", &youon[26]},

    {"jya", &youon[24]},
    {"jyu", &youon[25]},
    {"jyo", &youon[26]},

    {"bya", &youon[27]},
    {"byu", &youon[28]},
    {"byo", &youon[29]},

    {"pya", &youon[30]},
    {"pyu", &youon[31]},
    {"pyo", &youon[32]},

    // Other chiisai kana
    {"fa", &combination[0]},
    {"va", &combination[1]},
    {"tsa", &combination[2]},

    {"fi", &combination[3]},
    {"vi", &combination[4]},
    {"tsi", &combination[5]},
    {"si", &combination[6]},
    {"zi", &combination[7]},
    {"ti", &combination[8]},
    {"di", &combination[9]},

    {"tu", &combination[10]},
    {"du", &combination[11]},
 
    {"fe", &combination[12]},
    {"ve", &combination[13]},
    {"she", &combination[14]},
    {"je", &combination[15]},
    {"che", &combination[16]},
    {"tse", &combination[17]},

    {"fo", &combination[18]},
    {"vo", &combination[19]},
    {"tso", &combination[20]},

    {"kwa", &combination[21]},
    {"kwi", &combination[22]},
    {"kwe", &combination[23]},

    {"gwa", &combination[24]},
    {"gwi", &combination[25]},
    {"gwe", &combination[26]}
};

// x/l + kana = chiisai
const Mapping chiisaiKana[] = {
    {"a", &chiisai[0]},
    {"i", &chiisai[1]},
    {"u", &chiisai[2]},
    {"e", &chiisai[3]},
    {"o", &chiisai[4]},
    {"wa", &chiisai[5]},
    {"tsu", &chiisai[6]},
    {"ka", &chiisai[7]},
    {"ke", &chiisai[8]}
};

#endif