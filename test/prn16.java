// prn16.java

// This file is a minimal test case for a problem
// reported by Colin Watson (maintainer of CCCC for
// the Debian Linux distribution).

// The problem reported by Colin related to unit test
// prn14, for which the generated .db file differed
// from the reference copy on some (but not all) 
// architecture platforms.  The difference was the 
// inclusion in the .db file of a line which read:
// CCCC_Module@@@
// This line implies that a module with an empty string
// as its name has been added to the internal database
// for some reason.

// Colin was kind enough to investigate the problem and
// come up with a minimal sample which triggered the problem
// which the code of this example is based on.

// On investigation, I found that the addition of the 
// module with the empty name is occurring as a result
// of the parser executing the action associated with
// the 'implementsClause' rule defined in java.g 
// despite the fact that the 'implements' keyword
// does not appear (outside the comment) in the sample
// code.  The action for this rule contains a call
// to ParseStore::record_userel_extent.
// For the moment, I lack the energy to work out why 
// the generated parser code is executing this action, 
// however I have modified the code of record_userel_extent
// to check client and server name and do 
// nothing if either is the empty string.

public class ImageOps /* implements ChangeListener */ 
{
  public ImageOps() { for (int i = 0;;) {} }
}


