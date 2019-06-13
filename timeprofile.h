int CREATION                      = 1;

int BEGIN_PROCESSING              = 2;
int END_PROCESSING                = 3;
int ENQUEUE                       = 4;
int DEQUEUE                       = 5;
int BEGIN_COMPUTATION             = 6;
int END_COMPUTATION               = 7;

int BEGIN_INTERRUPT               = 8;
int END_INTERRUPT                 = 9;
int MESSAGE_RECV                  = 10;
int BEGIN_TRACE                   = 11;
int END_TRACE                     = 12;
int USER_EVENT                    = 13;
int BEGIN_IDLE                    = 14;
int END_IDLE                      = 15;
int BEGIN_PACK                    = 16;
int END_PACK                      = 17;
int BEGIN_UNPACK                  = 18;
int END_UNPACK                    = 19;
int CREATION_BCAST                = 20;

int CREATION_MULTICAST            = 21;

/* A record for a user supplied integer value, likely a timestep */
int USER_SUPPLIED                 = 26;

/* A record for the memory usage */
int MEMORY_USAGE                  = 27;

/* A record for a user supplied string */
int USER_SUPPLIED_NOTE            = 28;
int USER_SUPPLIED_BRACKETED_NOTE  = 29;


int BEGIN_USER_EVENT_PAIR         = 98;
int END_USER_EVENT_PAIR           = 99;
int USER_EVENT_PAIR               = 100;
int USER_STAT 		          = 32;

/* user category */
int NEW_CHARE_MSG                 = 0;
int FOR_CHARE_MSG                 = 2;
int BOC_INIT_MSG                  = 3;

int LDB_MSG                       = 12;
int QD_BOC_MSG                    = 14;
int QD_BROADCAST_BOC_MSG          = 15;
