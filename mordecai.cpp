/* these are some commands that we can start with now
   to give places for people to spend their tokens
   the first command lets people transfer tokens in their
   account into practice sessions.
   This is helpful for newbies, but most players
   that have a few remorts have practice sessions in the thousands.
   This will also allow them to use up their practice sessions.
   100 practice sessions can equal 1 bronze token.
   20  practice sessions can equal 1 brass token.
   whereas it will cost 1 brass token to buy a practice session.
   (5 brass = bronze)

   The command will be: transfer <token|sessions> <number>

   transfer token 1 - will transfer 1 brass token into a training session.
   transfer session 1 - will transfer 20 sessions into a brass token.
   ------------------------

   the command convert will be used for players to make 1 larger
   denomonation in their account into the next smaller denomonation.

   ie: 1 gold into 10 silver.
       1 silver into 10 bronze.
       1 bronze into 5 brass.

       convert <brass|bronze|silver|gold>
       it will just place that amount in your account for you to deduct.

   -------------------------mord-----------------------------

O======================================================================O
|Name: Soulstar            Class: [ Thief      ] |Level:        [ 255] |
|Race: Faun                Sex:   [ Male       ] |Age:          [  26] |
|-------------------------------|----------------+---------------------|
|Str: [17] [17] [100] [100]     |Weight:  [  4%] |Brass  Tokens:[ 100] |
|Int: [25] [17] Wis: [25] [17]  |Items:   [  4%] |Bronze Tokens:[ 100] |
|Con: [25] [17] Dex: [25] [17]  |Thirst:  [ -4%] |Silver Tokens:[ 100] |
|Cha: [25] [17]                 |Full:    [ -4%] |Gold   Tokens:[ 100] |
|Gold: [                      ] |Drunk:   [-10%] |                     |
|Bank: [                      ] |                |Fame         :[ 100] |
|-------------------------------+----------------+---------------------|
|Exp. Gained  :  [  999999000 ] |PKills:[    12] |Bank:  [         0 ] |
|Exp. to Level:  [ 3294968296 ] |PDeath:[    12] |Gold:  [    983897 ] |
|-------------------------------+----------------+---------------------|
|Hit   Points: [ 3050]  [ 3050] |SPEEDMIN: [  8] |Alignment:   [-1000] |
|Mana  Points: [ 2702]  [ 2702] |SPEEDMAX: [ 20] |Hit Bonus:   [   23] |
|Move  Points: [ 1747]  [ 1747] |                |Dam Bonus:   [   78] |
|Damage Percent Resist: [  90%] |Mail:     [yes] |Practices:   [12343] |
O======================================================================O

     equip_char(ch, obj, where);

*/

#include "config.h"
#include "sysdep.h"

#include "structs.h"
#include "utils.h"
#include "comm.h"
#include "interpreter.h"
#include "handler.h"
#include "db.h"
#include "house.h"
#include "screen.h"
#include "constants.h"
#include "oasis.h"
#include "dg_scripts.h"
#include "spells.h"
#include "genmob.h"


/* external functions */
void convert_tokens ( Character *ch );
int wep_hands(OBJ_DATA *wep);

ACMD ( do_convert )
{
	char arg2[MAX_INPUT_LENGTH];
	int counter, amount = 1;
	struct obj_data *obj;

	if ( IS_NPC ( ch ) )
	{
		ch->Send ( "Silly mob, you don't collect tokens.\r\n" );
		return;
	}

	one_argument ( argument, arg2 );

	if ( !*arg2 )
	{
		ch->Send ( "Usage: convert <tokentype>.\r\n" );
		return;
	}


	if ( amount < 0 )
	{
		ch->Send ( "Your attempt at cheating has been logged.  The Imms will be notified.\r\n" );
		return;
	}

	if ( isname ( "brass", arg2 ) )
	{
		if ( GET_BRASS_TOKEN_COUNT ( ch ) >= amount )
		{
			ch->Send ( "You can't split a brass token. If you want to Deduct say so.\r\n" );
			return;
		}
		else
		{
			ch->Send ( "You don't have that many tokens on account.\r\n" );
			return;
		}
	}
	else if ( isname ( "bronze", arg2 ) )
	{
		if ( GET_BRONZE_TOKEN_COUNT ( ch ) >= amount )
		{
			ch->Send ( "%d tokens were deducted from your account and split to brass.\r\n",
			           amount );
			GET_BRONZE_TOKEN_COUNT ( ch ) -= amount;
			for ( counter = 0; counter < 5; counter++ )
			{
				obj = read_object ( 3300, VIRTUAL );
				if ( obj )
					obj_to_char ( obj, ch );
			}
			return;
		}
		else
		{
			ch->Send ( "You don't have that many tokens on account.\r\n" );
			return;
		}
	}
	else if ( isname ( "silver", arg2 ) )
	{
		if ( GET_SILVER_TOKEN_COUNT ( ch ) >= amount )
		{
			ch->Send ( "%d tokens were deducted from your account and split to bronze.\r\n",
			           amount );
			GET_SILVER_TOKEN_COUNT ( ch ) -= amount;
			for ( counter = 0; counter < 10; counter++ )
			{
				obj = read_object ( 3301, VIRTUAL );
				if ( obj )
					obj_to_char ( obj, ch );
			}

			return;
		}
		else
		{
			ch->Send ( "You don't have that many tokens on account.\r\n" );
			return;
		}
	}
	else if ( isname ( "gold", arg2 ) )
	{
		if ( GET_GOLD_TOKEN_COUNT ( ch ) >= amount )
		{
			ch->Send ( "%d tokens were deducted from your account and split.\r\n", amount );
			GET_GOLD_TOKEN_COUNT ( ch ) -= amount;
			for ( counter = 0; counter < 10; counter++ )
			{
				obj = read_object ( 3302, VIRTUAL );
				if ( obj )
					obj_to_char ( obj, ch );
			}

			return;
		}
		else
		{
			ch->Send ( "You don't have enough tokens on account.\r\n" );
			return;
		}
	}
	else
	{
		ch->Send ( "You can only deduct tokens from your account.\r\n" );
		return;
	}
	return;
}

ACMD ( do_convey )
{
	char arg1[MAX_INPUT_LENGTH];
	char arg2[MAX_INPUT_LENGTH];
	gold_int amount = 0;

	if ( IS_NPC ( ch ) )
	{
		ch->Send ( "Silly mob, you don't collect tokens.\r\n" );
		return;
	}

//	Removed Remort check per Molly. - Prometheus.
//
//	if ( GET_REMORT ( ch ) == -1 )
//	{
//		ch->Send ( "This command works for remorted players only.\r\n" );
//		return;
//	}

	two_arguments ( argument, arg2, arg1 );


	if ( !*arg1 || !*arg2 )
	{
		ch->Send ( "Usage: convey <token|gold|maxmove|award|tradepoints> <amount>.\r\n" );
		ch->Send ( "see HELP CONVEY for more info.\r\n"
		           "CONVEY gold <amount>, turns gold coins into exp points at 4 to 1 ratio\r\n"
		           "CONVEY maxmove 1, turns (num of times used x ) 10 mill into 100 maxmove\r\n" );
		return;
	}
	amount = atoll ( arg1 );

	if ( amount <= 0 && !isname ( arg1, "maxmove" ) && !isname ( arg2, "gold" ) )
	{
		*ch << "Your usage is wrong.\r\n";
		return;
	}

	if ( isname ( arg2, "tokens" ) )
	{
		if ( amount > 50 )
		{
			ch->Send ( "You can only convey 50 bronze tokens or less.\r\n" );
		}
		else
		{
			int silver_tokens = amount / 50;
			int bronze_tokens = ( amount - silver_tokens * 50 ) / 5;
			int brass_tokens  = amount - silver_tokens * 50 - bronze_tokens * 5;
			int new_gold_tokencount   = GET_GOLD_TOKEN_COUNT ( ch );
			int new_silver_tokencount = GET_SILVER_TOKEN_COUNT ( ch ) - silver_tokens;
			int new_bronze_tokencount = GET_BRONZE_TOKEN_COUNT ( ch ) - bronze_tokens;
			int new_brass_tokencount  = GET_BRASS_TOKEN_COUNT ( ch )  - brass_tokens;

			if ( new_brass_tokencount < 0 )
			{
				new_bronze_tokencount--;
				new_brass_tokencount = 5 + new_brass_tokencount;
			}
			if ( new_bronze_tokencount < 0 )
			{
				new_silver_tokencount--;
				new_bronze_tokencount = 10 + new_bronze_tokencount;
			}
			if ( new_silver_tokencount < 0 )
			{
				new_gold_tokencount--;
				new_silver_tokencount = 10 + new_silver_tokencount;
			}

			if ( new_gold_tokencount < 0 )
			{
				ch->Send ( "You don't have that many tokens on your account.\r\n" );
			}
			else
			{
				char buf[100];
				char *bufpointer=buf;
				int sessions=silver_tokens * 500 + bronze_tokens * 50 + brass_tokens * 5;
				bufpointer+=snprintf ( bufpointer, ( size_t ) ( 98 - ( bufpointer - buf ) ), "You convey " );
				if ( silver_tokens > 0 )
					bufpointer += snprintf ( bufpointer, ( size_t ) ( 98 - ( bufpointer - buf ) ), "%d silver token%s",
					                         silver_tokens,
					                         silver_tokens > 1 ? "s" : "" );
				if ( bronze_tokens > 0 )
					bufpointer += snprintf ( bufpointer, ( size_t ) ( 98 - ( bufpointer - buf ) ), "%s%s%d bronze token%s",
					                         silver_tokens > 0 && brass_tokens > 0  ? ", " : "",
					                         silver_tokens > 0 && brass_tokens == 0 ? " and " : "",
					                         bronze_tokens,
					                         bronze_tokens > 1 ? "s" : "" );
				if ( brass_tokens > 0 )
					bufpointer += snprintf ( bufpointer, ( size_t ) ( 98 - ( bufpointer - buf ) ), "%s%d brass token%s",
					                         silver_tokens > 0 || bronze_tokens > 0 ? " and " : "",
					                         brass_tokens,
					                         brass_tokens > 1 ? "s" : "" );
				bufpointer += snprintf ( bufpointer, ( size_t ) ( 98 - ( bufpointer - buf ) ), " to %d training session%s.\r\n",
				                         sessions,
				                         sessions > 1 ? "s":"" );
				ch->Send ( buf );
				GET_GOLD_TOKEN_COUNT ( ch )   = new_gold_tokencount;
				GET_SILVER_TOKEN_COUNT ( ch ) = new_silver_tokencount;
				GET_BRONZE_TOKEN_COUNT ( ch ) = new_bronze_tokencount;
				GET_BRASS_TOKEN_COUNT ( ch )  = new_brass_tokencount;
				GET_PRACTICES ( ch )         += sessions;
			}
		}
		/* no more session converting. It's EVIL!!!!
		    } else if (isname(arg2, "sessions")) {
		        if ((amount % 20)) {
		            ch->Send("The number must be devisable by 20.");
		            return;
		        }
		        if (amount < 20) {
		            ch->Send("The amount must be greater then 20.");
		            return;
		        }
		        if (!(amount <= 200)) {
		            ch->Send("The amount must be less then or equal to 200.");
		            return;
		        }
		        if (GET_PRACTICES(ch) >= amount) {
		            ch->Send("You convey %lld practice sessions to %lld bronze tokens.\r\n",
		                     amount, amount / 20);
		            GET_BRONZE_TOKEN_COUNT(ch) += amount / 20;
		            GET_PRACTICES(ch) -= amount;
		            convert_tokens(ch);

		            return;
		        } else {
		            ch->Send("You don't have that many sessions.\r\n");
		            return;
		        }
		*/
	}
	// This should be arg2 then gold not gold then arg2
	// Changed this from "gold" to "maxmove" since the rest of the
	// code does the next agruement. Prometheus.
//	else if ( isname ( arg2, "gold" ) )
//	{
	else if ( isname ( arg2, "maxmove" ) )
		{

			if ( ch->Gold ( 0, GOLD_ALL ) >= 10000000 * GET_CONVERSIONS (ch))
			{
				log ( "INFO: %s conveyed %lld gold into %d maxmove", GET_NAME ( ch ), ( gold_int ) ( 10000000 * GET_CONVERSIONS ( ch ) ), 100 );
				ch->Send ( "You convey %lld gold to %d maxmove.\r\n",
				           ( gold_int ) ( 10000000 * GET_CONVERSIONS(ch)), 100 );
				GET_MAX_MOVE ( ch ) += 100;
				ch->Gold ( -10000000 * GET_CONVERSIONS(ch), GOLD_ALL );
				GET_CONVERSIONS ( ch ) ++;
				ch->affect_total();

			}
			else
			{
				ch->Send ( "You can't afford to!\r\n" );
			}
			return;
		}

	else if (isname(arg2, "gold")) {

		if ( ! ( amount >= 4 ) )
		{
			ch->Send ( "The amount must be greater then 4.\r\n" );
			return;
		}
		if ( amount % 4 != 0 )
		{
			ch->Send ( "The amount must be a multiple of 4.\r\n" );
			return;
		}

		if ( ch->Gold ( 0, GOLD_ALL ) >= amount )
		{
			log ( "INFO: %s conveyed %lld gold into %lld exp", GET_NAME ( ch ), amount, amount/4 );
			ch->Send ( "You convey %lld gold to %lld exp points.\r\n", amount, amount / 4 );
			gain_exp ( ch, amount / 4 );
			ch->Gold ( -amount, GOLD_ALL );

			return;
		}
		else
		{
			ch->Send ( "You can't afford to!\r\n" );
		}

	}

	else if ( isname ( arg2, "award" ) )
	{


		if ( PLR_FLAGGED ( ch, PLR_HERO ) )
		{
			ch->Send ( "Sorry, can't do that.\r\n" );
			return;
		}

		if ( ( amount % 10 ) )
		{
			ch->Send ( "The amount must be a multiple of 10." );
			return;
		}

		if ( amount < 10 )
		{
			ch->Send ( "You can only convey 10 or more.\r\n" );
			return;
		}

		if ( amount > GET_AWARD ( ch ) )
		{
			ch->Send ( "You can't afford that action.\r\n" );
			return;
		}

		log ( "INFO: %s conveyed %d award points into %d bronze tokens", GET_NAME ( ch ), ( int ) amount, ( int ) ( amount/10 ) );

		ch->Send ( "You convey %d award points to %d bronze tokens.\r\n", ( int ) amount, ( int ) ( amount/10 ) );
		GET_BRONZE_TOKEN_COUNT ( ch ) += ( int ) ( amount/10 );
		GET_AWARD ( ch ) -= amount;
		convert_tokens ( ch );

	}
	else if ( isname ( arg2, "tradepoints" ) )
	{
		if ( amount < 1 )
		{
			ch->Send ( "You have to convey at least 1\r\n" );
			return;
		}

		if ( amount > TRADEPOINTS ( ch ) )
		{
			ch->Send ( "You can't afford that action.\r\n" );
			return;
		}
		ch->Send ( "You convey tradepoints for exp \r\nat the rate of 1 tradepoint per level 30 mob's exp equivilent.\r\n" );
		gain_exp ( ch, amount * mob_stats[30].exp );
		TRADEPOINTS ( ch ) -= amount;

	}
	else
	{
		ch->Send ( "You can only convey tokens, gold, maxmove, award points or trade points.\r\n" );
		return;
	}
	return;
}

ACMD ( do_swap )
{
	obj_data *w1 = GET_EQ ( ch, WEAR_WIELD );
	obj_data *w2 = GET_EQ ( ch, WEAR_WIELD_2 );

	if ( w1 == NULL || w2 == NULL )
{
		ch->Send ( "You are not dual wielding weapons!\r\n" );
		return;
	}


	if ( ( ( GET_OBJ_TYPE ( w1 ) != ITEM_WEAPON )
	        || ( GET_OBJ_TYPE ( w2 ) != ITEM_WEAPON ) ) )
	{
		ch->Send ( "You are not dual wielding WEAPONS.\r\n" );
		return;
	}
	if ( wep_hands ( w1 ) == 2 ) {
		ch->Send("You can't swap a two-handed weapon to your offhand.\r\n");
		return;
	}

	w1 = unequip_char ( ch, WEAR_WIELD );
	w2 = unequip_char ( ch, WEAR_WIELD_2 );
	equip_char ( ch, w1, WEAR_WIELD_2 );
	equip_char ( ch, w2, WEAR_WIELD );

	act ( "You swap hands using $p and $P.", FALSE, ch, w1, w2,  TO_CHAR );
	act ( "$n swaps hands using $p and $P.", TRUE, ch, w1, w2,   TO_ROOM );
	return;
}


/*swap hands wielding weapons*/
/*
ACMD(do_suicide)
 {
     if (IS_NPC(ch))
      return;

     if ( argument[0] == '\0' || str_cmp(argument, "yes"))
     {
       send_to_char( "If you mean it, type suicide 'yes'.\r\n", ch );
       return;
     }

     act("$n gives up the will to live.",TRUE, ch, NULL, NULL, TO_ROOM );
     act("You surrender the will to live.",FALSE, ch, NULL, NULL, TO_CHAR);
     raw_kill( ch, ch );
     return;
 }

*/