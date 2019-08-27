#include "BaseDB.h"

mysqlx::Session BaseDB::connect_to_session() {
	mysqlx::Session session("dt5.ehb.be", 33060, "1819WEBADV050", "xeze81");
	return session;
}
