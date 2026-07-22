1. Swap File
Automatically created while editing.
Stores unsaved changes.
Used after a crash with:
vim -r filename
2. Undo History
Allows previous edits to be reversed.
Works during the editing session.
Persistent undo can preserve history across sessions if enabled.
3. Registers
Temporary storage for copied or deleted text.
Useful for restoring content during editing.
Not intended for crash recovery.
4. Backup Files
Created before saving changes when backup options are enabled.
Protect the original file from accidental overwrites.
Do not include the most recent unsaved edits.
5. Auto-Recovery
On restart, Vim detects an existing swap file.
Prompts the user to recover unsaved work.
Helps restore changes made before the crash.
Most Reliable Recovery Strategy

The most reliable strategy is to enable swap files, backup files, and persistent undo together. After a crash, recover the document using vim -r filename, verify the recovered content, save it under a new name if necessary, and then replace the original file. This approach maximizes the chances of recovering unsaved work while preserving the original file and maintaining an edit history.
