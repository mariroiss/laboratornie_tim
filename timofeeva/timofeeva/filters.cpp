#include "filters.h"
#include "cs.h"
#include "pipe.h"
#include <unordered_map>

using namespace std;

bool ProverkaByRepair(Pipe& p, bool status)
{
	return p.GetRepair() == status;
}

