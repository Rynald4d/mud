
/* these are subskills  - mord*/
enum subskill_list {
    SUB_UNDEFINED, //0
    SUB_FURY_ATTACKS,
    SUB_NIGHT_REGEN,
    SUB_DRAIN_BLOOD,
    SUB_PILLAGE,
    SUB_REFINE_ORE,
    SUB_REFINE_GEMS,
    SUB_REPROCESS_ORE,
    SUB_REPROCESS_GEMS,
    SUB_INDUSTRY,
    SUB_MARKETING,//10
    SUB_BARTER,
    SUB_SOFT_MINING,
    SUB_HARD_MINING,
    SUB_UNDEFINED1,     //SUB_SHARPENING,
    SUB_UNDEFINED2,     //SUB_LEATHERWORK,
    SUB_UNDEFINED3,     //SUB_TAILORING,
    SUB_UNDEFINED4,     //SUB_SURVEYING,
    SUB_ELECTRONICS,
    SUB_SMALL_SHIELDS,
    SUB_LARGE_SHIELDS,//20
    SUB_DECYPHERING,
    SUB_HEAVY_WEAPONS,
    SUB_LIGHT_WEAPONS,
    SUB_UNDEFINE5,    //SUB_BREWING,
    SUB_SUPERVISING,
    SUB_MANAGEMENT,
    SUB_LEADERSHIP,
    SUB_GROUP_COORDINATION,
    SUB_HEAVY_ARMOR,
    SUB_MEDIUM_ARMOR,//30
    SUB_LIGHT_ARMOR,
    SUB_LIGHTSABER_PROF,
    SUB_LIGHTSABER_DOUBLE,
    SUB_DOGFIGHTING,
    SUB_COCKFIGHTING,
    SUB_STREETFIGHTING,
    SUB_DEVINE_WATER,
    SUB_CREATE_WELL,
    SUB_OPTICS,
    SUB_UNDEFINED6,   //SUB_MILLING,//40
    SUB_PAPERMAKING,
    SUB_SCROLLMAKING,
    SUB_UNDEFINED7,   //SUB_HEAT_MANAGEMENT,
    SUB_UNDEFINED8,   //SUB_GLASSWORK,
    SUB_UNDEFINED9,   //SUB_BOTTLEMAKING,
    SUB_UNDEFINED0,   //SUB_VIALMAKING,
    SUB_LUMBERJACK,
    SUB_TREEGUARD,
    SUB_LOYALSPEED,
    SUB_LOYALATTACK,//50
    SUB_LOYALDEFEND,
    SUB_LOYALDAMAGE,
    SUB_LYCAN,
    SUB_STUN_PHASER,
    SUB_JUGGLE,
    SUB_GAROTTE,
    SUB_DRAGON_SUMMONING,
    SUB_DRAGON_TAMING,
    SUB_DRAGON_ENCHANTING,
    SUB_DRAGON_MOUNTING,//60
    SUB_DRAGON_MASTERY,
    SUB_DRAGON_FLYING,
    SUB_DRAGON_CARGO,
    SUB_DRAGON_PASSENGERS,//64
    SUB_BEASTTAME,
    SUB_BEASTTONGUE,
    SUB_BEASTMASTER,
    SUB_TASKMASTER,
    SUB_UNDEAD_OVERLORD,
    SUB_UNDEAD_DEMON, //70
    SUB_UNDEAD_MINORDEMON,
    SUB_UNDEAD_DRAGON,
    SUB_UNDEAD_MASTER,
    SUB_UNDEAD_SUMMON,
    SUB_UNDEAD_WORSHIP,//75
    SUB_TRIP,
    SUB_THROTTLE,
    SUB_MASK,
    SUB_CLOAK,
    SUB_SHADOWCLOAK,
    SUB_BALANCE,
    SUB_TUMBLE,
    SUB_CLOWN,
    SUB_TRAPEZE,
    SUB_UNDEFINED10,   //SUB_CHARCOALBURNER, //85
    SUB_UNDEFINED11,   //SUB_BRICKMAKING,
    SUB_TUNNELING,
    SUB_REPEL_SANC,
    SUB_UNDYING,
    SUB_SWEEP_ATTACK,
    SUB_ASSEMBLE,
    SUB_BAKE,
    SUB_BREW,
    SUB_CRAFT,
    SUB_FLETCH, //95
    SUB_KNIT,
    SUB_MAKE,
    SUB_MIX,
    SUB_THATCH,
    SUB_WEAVE, //100
    SUB_FORGE,
    // Additional subskills added per Molly
    SUB_INSTRUMENT_MAKER,
    SUB_PAINTER,
    SUB_POTTER,
    SUB_REPAIRMAN, //105
    SUB_SCULPTOR,
    SUB_ALCHEMIST,
    SUB_BREWER,
    SUB_DISTILLER,
    SUB_PERFUMER, //110
    SUB_POTION_MAKER,
    SUB_GAFFER,
    SUB_GLAZIER,
    SUB_MARVER,
    SUB_MAESTRO, //115
    SUB_MIRRORMAKER,
    SUB_TANNER,
    SUB_FURRIER,
    SUB_SHOEMAKER,
    SUB_GLOVEMAKER, //120
    SUB_ARMOURER,
    SUB_METALLURGIST,
    SUB_BLACKSMITH,
    SUB_FARRIER,
    SUB_UNDEFINED12,       //SUB_GOLDSMITH, //125
    SUB_WEAPONSMITH,
    SUB_QUARRIER,
    SUB_MASONER,
    SUB_STONECUTTER,
    SUB_GEMCUTTER, //130
    SUB_CONSTRUCTOR,
    SUB_WEAVER,
    SUB_UNDEFINED13,        //SUB_ROPEMAKER,
    SUB_TAILOR,
    SUB_EMBROIDERER, //135
    SUB_ROBEMAKER,
    SUB_WOODSMAN,
    SUB_MILLER,
    SUB_CARPENTER,
    SUB_CABINETMAKER, //140
    SUB_SHIPBUILDER,
    TOP_SUB_DEFINE
};



enum sub_status_types {
    STATUS_TYPE_TRAINABLE,
    STATUS_TYPE_ONOFF
};

enum sub_professions_list {
    PROF_MISC,
    PROF_NECROMANCER,
    PROF_DRAGONMASTER,
    PROF_PERFORMER,
    PROF_WOODSMAN,
    PROF_BEASTMASTER,
    PROF_GLAZIER,
    PROF_SCRIBE,
    PROF_BUSINESS,
    PROF_COMMERCE,
    PROF_MINER,
    PROF_BREWER,
    PROF_COMBATANT,
    PROF_TANNER,
    PROF_MILLER,
    PROF_WEAVER,
    PROF_BLACKSMITH,
    PROF_TAILOR,
    PROF_TECH,
    PROF_MANAGEMENT,
    PROF_PILOT,
    PROF_FARRIER,
    PROF_GOLDSMITH,
    PROF_METALLURGIST,
    PROF_WEAPONSMITH,
    PROF_FURRIER,
    PROF_SHOEMAKER,
    PROF_GLOVEMAKER,
    PROF_ARMOURER,
    PROF_CARDER,
    PROF_SPINNER,
    PROF_DRESSMAKER,
    PROF_CARPENTER,
    PROF_CABINETMAKER,
    PROF_SHIPBUILDER,
    PROF_QUARRIER,
    PROF_COLLIER,
    PROF_BRICKMAKER,
    PROF_MASON,
    PROF_MIRRORMAKER,
    PROF_CONTRACTOR,
    PROF_ARTISAN,
    PROF_GLASSWORK,
    PROF_LEATHERWORK,
    PROF_METALWORK,
    PROF_STONEWORK,
    PROF_TEXTILEWORK,
    PROF_WOODWORK,
    PROF_PALADIN,
    // New Professions per Molly
    PROF_JEDI,
    PROF_BRAVO,
    PROF_SPACEPILOT,
    PROF_AFFLICTION_VAMPIRE,
    PROF_AFFLICTION_WEREWOLF,

    PROF_MAX
};

enum prof_group_list {
    PGRP_MISC,
    PGRP_METALWORKER,
    PGRP_LEATHERWORKER,
    PGRP_TEXTILEWORKER,
    PGRP_WOODWORKER,
    PGRP_STONEWORKER,
    PGRP_ARTIST,
    PGRP_FERMENTER,
    PGRP_GLASSWORKER,
    // More Profession groups per Molly
    PGRP_COMBAT,
    PGRP_AFFLICTION,
    PGRP_SUMMONING,
    PGRP_CONTROL,

    PGRP_MAX
};

enum sub_status_toggle {
    STATUS_OFF,
    STATUS_ON
};

struct sub_list {
    subskill_list subskill;
    int learn;
    sub_status_toggle status;

    sub_list() {
        subskill = SUB_UNDEFINED;
        learn = 0;
        status = STATUS_OFF;
    }

    ~sub_list() {}

    bool operator==(enum subskill_list s) { return this->subskill == s;}
    bool operator==(int s) {return (int)this->subskill == s;}
    bool operator<(const sub_list &b) { return (this->subskill < b.subskill);}

};



#define SUB_TYPE_TEACHABLE 	(1 << 0)
#define SUB_TYPE_EXP 		(1 << 1)
#define SUB_TYPE_CMD		(1 << 2)
#define SUB_TYPE_AUTO 		(1 << 3)
#define SUB_TYPE_DEFAULT_ON     (1 << 4)
#define SUB_TYPE_PROF		(1 << 5)



