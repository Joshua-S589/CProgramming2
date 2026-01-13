int bladecnt=92;
int mainBladecnt=16;
int assistBladecnt=13;
int ratchetIntegratedBitcnt=2;
int ratchetcnt=33;
int bitcnt=44;
int mlccnt=2;
int plccnt=12;
char blade[108][50]={"Black Shell", "Cobalt Dragoon", "Cobalt Drake", "Crimson Garuda", "Dran Dagger", "Dran Sword", "Hells Chain", "Hells Scythe", "Knight Lance", "Knight Shield", "Leon Claw", "Phoenix Feather", "Phoenix Wing", "Rhino Horn", "Samurai Calibur", "Shark Edge", "Shelter Drake", "Sphinx Cowl", "Tricera Press", "Tyranno Beat", "Unicorn Sting", "Viper Tail", "Weiss Tiger", "Whale Wave", "Wizard Arrow", "Wyvern Gale",
     "Aero Pegasus", "Clock Mirage", "Dran Buster", "Ghost Circle", "Golem Rock", "Hells Hammer", "Hover Wyvern", "Impact Drake", "Knight Mail", "Leon Crest", "Mummy Cusrse", "Orochi Cluster", "Phoenix Rudder", "Samurai Saber", "Scorpio Spear", "Shark Scale", "Shinobi Shadow", "Silver Wolf", "Stun Medusa", "Viking Hack", "Wizard Rod", 
     "Draciel Shield", "Dragoon Storm", "Dranzer Spiral", "Driger Slash", "Lightning L-Drago", "Rock Leon", "Storm Pegasus", "Victory Valkyrie", "Xeno Xcalibur",
     "Bite Croc", "Gill Shark", "Knife Shinobi", "Roar Tyranno", "Savvage Bear", "Steel Samurai", "Tackle Goat", "Talon Ptera", "Tusk Mammoth", "Yell Kong",
     "Bumblebee", "Megatron", "Optimus Primal", "Optimus Prime", "Shockwave", "Starscream", "Chewbacca", "Darth Vader", "General Grievous", "Luke Skywalker", "Moff Gideon", "Obi-Wan Kenobi", "Stormtrooper", "The Mandalorian", "Captain America", "Green Goblin", "Iron Man", "Miles Morales", "Red Hulk", "Spider-Man", "Thanos", "Venom", "Mosasaurus", "Quetzalcoatlus", "Spinosaurus", "T Rex",
     "Arc", "Blast", "Brave", "Brush", "Dark", "Eclipse", "Fang", "Flame", "Flare", "Hunt", "Might", "Reaper", "Volt", "Antler", "Fort", "Wriggle"};
char assist_blade[13][50]={"A", "B", "C", "D", "F", "H", "J", "M", "R", "S", "T", "W", "Z"};
char ratchet[35][50]={"Op", "Tr", "0-60", "0-70", "0-80", "1-60", "1-70", "1-80", "2-60", "2-70", "2-80", "3-60", "3-70", "3-80", "3-85", "4-50", "4-55", "4-60", "4-70", "4-80", "5-60", "5-70", "5-80", "M-85", "6-60", "6-70", "6-80", "7-55", "7-60", "7-70", "7-80", "9-60", "9-65", "9-70", "9-80"};
char bit[44][50]={"A", "B", "BS", "C", "D", "DB", "E", "F", "FB", "G", "GB", "GF", "GN", "GP", "GR", "H", "HN", "HT", "J", "K", "L", "LF", "LO", "LR", "M", "MN", "N", "O", "P", "Q", "R", "RA", "S", "T", "TK", "TP", "U", "UF", "UN", "V", "W", "WB", "WW", "Z"};
char lock_chip[14][50]={"Valkyrie", "Emperor", "Cerberus", "Dran", "Fox", "Hells", "Pegasus", "Perseus", "Phoenix", "Rhino", "Sol", "Whale", "Wizard", "Wolf"};
int bladeCollection[108];
int bladeCollectionClone[108];
int assistBladeCollection[13];
int assistBladeCollectionClone[13];
int ratchetCollection[35];
int ratchetCollectionClone[35];
int bitCollection[44];
int bitCollectionClone[44];
int lockChipCollection[14];
int lockChipCollectionClone[14];