#import <Foundation/NSObject.h>
#import <AppKit/NSNibDeclarations.h>

@class ABPerson;
@class NSWindow;
@class NSTableView;
@class MVTableView;
@class MVChatConnection;
@class ABPeoplePickerController;

typedef enum {
	MVNoSortOrder = 0,
	MVAvailabilitySortOrder,
	MVFirstNameSortOrder,
	MVLastNameSortOrder,
	MVServerSortOrder
} MVBuddyListSortOrder;

@interface MVBuddyListController : NSWindowController <JVInspectionDelegator> {
@private
	IBOutlet MVTableView *buddies;
	IBOutlet NSMenu *actionMenu;
	IBOutlet NSButton *sendMessageButton;
	IBOutlet NSButton *infoButton;

	IBOutlet NSWindow *pickerWindow;
	IBOutlet NSView *pickerView;

	IBOutlet NSWindow *newPersonWindow;
	IBOutlet NSTextField *nickname;
	IBOutlet NSPopUpButton *server;
	IBOutlet NSTextField *firstName;
	IBOutlet NSTextField *lastName;
	IBOutlet NSTextField *email;
	IBOutlet NSImageView *image;
	IBOutlet NSButton *addButton;

	NSMutableSet *_buddyList;
	NSMutableSet *_onlineBuddies;
	NSMutableArray *_buddyOrder;
	NSMutableDictionary *_buddyInfo;
	ABPeoplePickerController* _picker;
	NSString *_addPerson;

	BOOL _showFullNames;
	BOOL _showNicknameAndServer;
	BOOL _showIcons;
	BOOL _showOfflineBuddies;
	MVBuddyListSortOrder _sortOrder;

	float _animationPosition;
	NSMutableArray *_oldPositions;
	NSTimer *_animationTimer;
	BOOL _viewingTop;
	BOOL _needsToAnimate;
	BOOL _animating;
}
+ (MVBuddyListController *) sharedBuddyList;

- (IBAction) getInfo:(id) sender;

- (IBAction) showBuddyList:(id) sender;

- (IBAction) showBuddyPickerSheet:(id) sender;
- (IBAction) cancelBuddySelection:(id) sender;
- (IBAction) confirmBuddySelection:(id) sender;

- (IBAction) showNewPersonSheet:(id) sender;
- (IBAction) cancelNewBuddy:(id) sender;
- (IBAction) confirmNewBuddy:(id) sender;

- (IBAction) messageSelectedBuddy:(id) sender;
- (IBAction) sendFileToSelectedBuddy:(id) sender;

- (void) setShowFullNames:(BOOL) flag;
- (BOOL) showFullNames;
- (IBAction) toggleShowFullNames:(id) sender;

- (void) setShowNicknameAndServer:(BOOL) flag;
- (BOOL) showNicknameAndServer;
- (IBAction) toggleShowNicknameAndServer:(id) sender;

- (void) setShowIcons:(BOOL) flag;
- (BOOL) showIcons;
- (IBAction) toggleShowIcons:(id) sender;

- (void) setShowOfflineBuddies:(BOOL) flag;
- (BOOL) showOfflineBuddies;
- (IBAction) toggleShowOfflineBuddies:(id) sender;

- (void) setSortOrder:(MVBuddyListSortOrder) order;
- (MVBuddyListSortOrder) sortOrder;
- (IBAction) sortByAvailability:(id) sender;
- (IBAction) sortByFirstName:(id) sender;
- (IBAction) sortByLastName:(id) sender;
- (IBAction) sortByServer:(id) sender;
@end
