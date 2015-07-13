// prn8.java
// SF Bugtracker bug #226676 
// reported by Eric Pischel

public class EwoisErrorHandler 
{ 
	public synchronized void handleError( int fehlertyp ) 
	{ 
		String lvTyp = ""; 
		switch (fehlertyp) 
		{ 
		case WARNING: 
			lvTyp = "Warnung"; 
			break; 
		case LOGINFO: 
			lvTyp = "LogInfo"; 
			break; 
		} 
		StringBuffer buffer = new StringBuffer(lvTyp); 
		buffer.append("Zeit: ").append(""); 
	} 
	int WARNING = 1; 
	int LOGINFO = 2; 
} 
