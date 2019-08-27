#pragma once
#include "include/mysqlx/xdevapi.h"

class BaseDB {
public:
	static mysqlx::Session connect_to_session();
};
