#ifndef PARTS_LIST_BEYBLADE_X_H
#define PARTS_LIST_BEYBLADE_X_H
int bladecnt=108;
int uxExtendedcnt=7;
int mainBladecnt=16;
int metalBladecnt=7;
int assistBladecnt=19;
int overBladecnt=7;
int ratchetIntegratedBitcnt=2;
int ratchetcnt=37;
int bitcnt=51;
int mlccnt=2;
int plccnt=27;
int simpleRatchetcnt=5;
int simpleBladecnt=1;
int bladeBxcnt=31;
int bladeUxcnt=21;
int clockMiragenum=1;
char blade[138][50]={"Aether Ring", "Black Shell", "Cobalt Dragoon", "Cobalt Drake", "Crimson Garuda", "Croc Crunch", "Cyclopse Eye", "Dran Dagger", "Dran Strike", "Dran Sword", "Heavens Ring", "Hells Chain", "Hells Scythe", "Horus Shatter", "Knight Lance", "Knight Shield", "Leon Claw", "Luster Dragoon", "Phoenix Feather", "Phoenix Wing", "Rhino Horn", "Samurai Calibur", "Sieg Superion", "Shark Edge", "Shelter Drake", "Sphinx Cowl", "Tricera Press", "Tyranno Beat", "Unicorn Sting", "Viper Tail", "Weiss Tiger", "Whale Wave", "Wizard Arrow", "Wyvern Gale",
     "Dran Sword V2", "Hells Scythe V2", "Knight Shield", "Wizard Arrow V2",
     "Aero Pegasus", "Clock Mirage", "Dran Buster", "Ghost Circle", "Golem Rock", "Hells Hammer", "Hover Wyvern", "Impact Drake", "Knight Mail", "Leon Crest", "Mummy Cusrse", "Orochi Cluster", "Phoenix Rudder", "Samurai Saber", "Scorpio Spear", "Shark Scale", "Shinobi Shadow", "Silver Wolf", "Stun Medusa", "Viking Hack", "Wizard Rod", 
     "Draciel Shield", "Dragoon Storm", "Dranzer Spiral", "Driger Slash", "Lightning L-Drago", "Rock Leon", "Storm Pegasus", "Storm Spriggan", "Victory Valkyrie", "Xeno Xcalibur",
     "Clamp Crab", "Gill Shark", "Knife Shinobi", "Ridge Triceratops", "Roar Tyranno", "Savvage Bear", "Steel Samurai", "Tackle Goat", "Talon Ptera", "Tusk Mammoth", "Yell Kong",
     "Bumblebee", "Megatron", "Optimus Primal", "Optimus Prime", "Shockwave", "Starscream", "Chewbacca", "Darth Vader", "General Grievous", "Luke Skywalker", "Moff Gideon", "Obi-Wan Kenobi", "Stormtrooper", "The Mandalorian", "Captain America", "Doctor Doom", "Green Goblin", "Hulk", "Iron Man", "Miles Morales", "Mister Fantastic", "Red Hulk", "Spider-Man", "Thanos", "Venom", "Mosasaurus", "Quetzalcoatlus", "Spinosaurus", "T Rex",
     "Aegis Rampart", "Bison Valor", "Bullet Griffon", "Glory Valkyrie", "Hells Nether", "Jaguar Seize", "Shinobi Cutter",
     "Arc", "Blast", "Brave", "Brush", "Dark", "Eclipse", "Fang", "Flame", "Flare", "Hunt", "Might", "Reaper", "Volt", "Antler", "Fort", "Wriggle",
     "Blitz", "Delta", "Fortress", "Hurricane", "Rage", "Tread", "Whip"};
char assist_blade[19][50]={"A", "B", "C", "D", "E", "F", "G", "H", "J", "K", "M", "O", "Q", "R", "S", "T", "V", "W", "Z"};
char ratchet[37][50]={"Op", "Tr", "0-60", "0-70", "0-80", "1-50", "1-60", "1-70", "1-80", "2-60", "2-70", "2-80", "3-60", "3-70", "3-80", "3-85", "4-50", "4-55", "4-60", "4-70", "4-80", "5-50", "5-60", "5-70", "5-80", "M-85", "6-60", "6-70", "6-80", "7-55", "7-60", "7-70", "7-80", "8-70", "8-80", "9-60", "9-65", "9-70", "9-80"};
char bit[51][50]={"A", "B", "BS", "C", "D", "DB", "DS", "E", "F", "FF", "FB", "G", "GB", "GF", "GN", "GP", "GR", "GU", "H", "HN", "HT", "I", "J", "K", "L", "LC", "LF", "LO", "LP", "LR", "M", "MN", "N", "Nr", "O", "P", "Q", "R", "RA", "S", "T", "TK", "TP", "U", "UF", "UN", "V", "W", "WB", "WW", "Y", "Z"};
char lock_chip[29][50]={"Valkyrie", "Emperor", "AFC", "Bahamut", "Brachio", "Cerberus", "Croc", "Drake", "Dran", "Enlil", "Eva", "Fox", "Hells", "Hornet", "Knight", "Kraken", "NFC", "Pegasus", "Perseus", "Phoenix", "Ragna", "Rhino", "Sol", "Stag", "Tiga", "Unicorn", "Whale", "Wizard", "Wolf"};
char over_blade[7][50]={"B", "D", "F", "G", "I", "O", "T"};
char simple_ratchet[5][50]={"3-85", "4-55", "M-85", "7-55", "9-65"};
char simple_blade[1][50]={"Clock Mirage"};
int bladeCollection1[138];
int bladeCollectionClone1[138];
int bladeCollection2[138];
int bladeCollectionClone2[138];
int assistBladeCollection1[19];
int assistBladeCollectionClone1[19];
int assistBladeCollection2[19];
int assistBladeCollectionClone2[19];
int overBladeCollection1[7];
int overBladeCollectionClone1[7];
int overBladeCollection2[7];
int overBladeCollectionClone2[7];
int ratchetCollection1[37];
int ratchetCollectionClone1[37];
int ratchetCollection2[37];
int ratchetCollectionClone2[37];
int bitCollection1[51];
int bitCollectionClone1[51];
int bitCollection2[51];
int bitCollectionClone2[51];
int lockChipCollection1[29];
int lockChipCollectionClone1[29];
int lockChipCollection2[29];
int lockChipCollectionClone2[29];
int simpleRatchetCollection1[5];
int simpleRatchetCollectionClone1[5];
int simpleRatchetCollection2[5];
int simpleRatchetCollectionClone2[5];
char combo_list_player_1[1000][1000];
char combo_list_player_2[1000][1000];
char blade_final[1000];
char blade_a[100];
#endif