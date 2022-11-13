#ifndef KANA_H
#define KANA_H
#include <string>

struct Kana {
    std::string hiragana;
    std::string katakana;
};

struct Symbol {
    std::string romaji;
    const Kana& kana;
};

const Kana regular[] = {
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

const Kana combining[] = {
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

static const Symbol symbols[] = {
    // Normal Kana
    {"a", regular[0]},
    {"i", regular[1]},
    {"u", regular[2]},
    {"e", regular[3]},
    {"o", regular[4]},

    {"ka", regular[5]},
    {"ki", regular[6]},
    {"ku", regular[7]},
    {"ke", regular[8]},
    {"ko", regular[9]},

    {"sa", regular[10]},
    {"shi", regular[11]},
    {"su", regular[12]},
    {"se", regular[13]},
    {"so", regular[14]},

    {"ta", regular[15]},
    {"chi", regular[16]},
    {"tsu", regular[17]},
    {"te", regular[18]},
    {"to", regular[19]},

    {"na", regular[20]},
    {"ni", regular[21]},
    {"nu", regular[22]},
    {"ne", regular[23]},
    {"no", regular[24]},

    {"ha", regular[25]},
    {"hi", regular[26]},
    {"fu", regular[27]},
    {"he", regular[28]},
    {"ho", regular[29]},

    {"ma", regular[30]},
    {"mi", regular[31]},
    {"mu", regular[32]},
    {"me", regular[33]},
    {"mo", regular[34]},

    {"ya", regular[35]},
    {"yu", regular[36]},
    {"yo", regular[37]},

    {"ra", regular[38]},
    {"ri", regular[39]},
    {"ru", regular[40]},
    {"re", regular[41]},
    {"ro", regular[42]},

    {"wa", regular[43]},
    {"wi", regular[44]},
    {"we", regular[45]},
    {"wo", regular[46]},

    {"n", regular[47]},
    {"nn", regular[47]},

    // Dakuon / Handakuon
    {"ga", dakuon[0]},
    {"gi", dakuon[1]},
    {"gu", dakuon[2]},
    {"ge", dakuon[3]},
    {"go", dakuon[4]},

    {"za", dakuon[5]},
    {"ji", dakuon[6]},
    {"zu", dakuon[7]},
    {"ze", dakuon[8]},
    {"zo", dakuon[9]},

    {"da", dakuon[10]},
    {"di", dakuon[11]},
    {"dzu", dakuon[12]},
    {"de", dakuon[13]},
    {"do", dakuon[14]},

    {"ba", dakuon[15]},
    {"bi", dakuon[16]},
    {"bu", dakuon[17]},
    {"be", dakuon[18]},
    {"bo", dakuon[19]},

    {"pa", dakuon[20]},
    {"pi", dakuon[21]},
    {"pu", dakuon[22]},
    {"pe", dakuon[23]},
    {"po", dakuon[24]},

    // Youon
    {"kya", youon[0]},
    {"kyu", youon[1]},
    {"kyo", youon[2]},

    {"sha", youon[3]},
    {"shu", youon[4]},
    {"sho", youon[5]},

    {"cha", youon[6]},
    {"chu", youon[7]},
    {"cho", youon[8]},

    {"nya", youon[9]},
    {"nyu", youon[10]},
    {"nyo", youon[11]},

    {"hya", youon[12]},
    {"hyu", youon[13]},
    {"hyo", youon[14]},

    {"mya", youon[15]},
    {"myu", youon[16]},
    {"myo", youon[17]},

    {"rya", youon[18]},
    {"ryu", youon[19]},
    {"ryo", youon[20]},

    {"gya", youon[21]},
    {"gyu", youon[22]},
    {"gyo", youon[23]},

    {"ja", youon[24]},
    {"ju", youon[25]},
    {"jo", youon[26]},

    {"jya", youon[24]},
    {"jyu", youon[25]},
    {"jyo", youon[26]},

    {"bya", youon[27]},
    {"byu", youon[28]},
    {"byo", youon[29]},

    {"pya", youon[30]},
    {"pyu", youon[31]},
    {"pyo", youon[32]},

    // Other chiisai kana
    {"fa", combining[0]},
    {"va", combining[1]},
    {"tsa", combining[2]},

    {"fi", combining[3]},
    {"vi", combining[4]},
    {"tsi", combining[5]},
    {"si", combining[6]},
    {"zi", combining[7]},
    {"ti", combining[8]},
    {"di", combining[9]},

    {"tu", combining[10]},
    {"du", combining[11]},
 
    {"fe", combining[12]},
    {"ve", combining[13]},
    {"she", combining[14]},
    {"je", combining[15]},
    {"che", combining[16]},
    {"tse", combining[17]},

    {"fo", combining[18]},
    {"vo", combining[19]},
    {"tso", combining[20]},

    {"kwa", combining[21]},
    {"kwi", combining[22]},
    {"kwe", combining[23]},

    {"gwa", combining[24]},
    {"gwi", combining[25]},
    {"gwe", combining[26]},

    {"xa", chiisai[0]},
    {"xi", chiisai[1]},
    {"xu", chiisai[2]},
    {"xe", chiisai[3]},
    {"xo", chiisai[4]},
    {"xwa", chiisai[5]},
    {"xtsu", chiisai[6]},
    {"xka", chiisai[7]},
    {"xke", chiisai[8]},

    {"la", chiisai[0]},
    {"li", chiisai[1]},
    {"lu", chiisai[2]},
    {"le", chiisai[3]},
    {"lo", chiisai[4]},
    {"lwa", chiisai[5]},
    {"ltsu", chiisai[6]},
    {"lka", chiisai[7]},
    {"lke", chiisai[8]}
};

#endif