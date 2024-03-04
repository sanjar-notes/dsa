# dsa
> previously (dsa_with_cpp)

There are 3 notebooks:
1. **Introduction to C++** - For beginners
2. **Data Structures with C++** - covers basic algorithms also - search, sort
3. **Competitive Programming tips** - C++ is used

To use these notes: View here on GitHub or clone the repo (and open with Markdown friendly editor).

These notes were created while doing a course from CodingNinjas.com.



> [!note] Some message here comes I don't know what
> Description of Obsidian callout

"You do not rise to the level of your goals. You fall to the level of your systems." by James Clear ^quote-of-the-day

Internal links
Learn how to link to notes, attachments, and other files from your notes, using internal links. By linking notes, you can create a network of knowledge.

Obsidian can automatically update internal links in your vault when you rename a file. If you want to be prompted instead, you can disable it under Settings → Files & Links → Automatically update internal links.

Supported formats for internal links
Obsidian supports the following link formats:

Hello Destination ^some-id

Wikilink: [[Three laws of motion]]
Markdown: [Three laws of motion](Three%20laws%20of%20motion.md)
The examples above are equivalent—they appear the same way in the editor, and links to the same note.

Note
# markdown-header-my-paragraph-title
When using the Markdown format, make sure to URL encode the link destination. For example, blank spaces become %20.

By default, due to its more compact format, Obsidian generates links using the Wikilink format. If interoperability is important to you, you can disable Wikilinks and use Markdown links instead.

To use the Markdown format:

Open Settings.
Under Files & Links, disable Use [[Wikilink]].
Even if you disable the Wikilink format, you can still autocomplete links by typing two square brackets [[. When you select one of the suggested files, Obsidian instead generates a Markdown link.

Link to a file
To create a link while in Editing view, use either of the following ways:

Type [[ in the editor and then select the file you want to create a link to.
Select text in the editor and then type [[.
Open the Command palette and then select Add internal link.
While you can link to any of the Accepted file formats, links to file formats other than Markdown needs to include a file extension, such as [[Figure 1.png]].

Link to a heading in a note
You can link to specific headings in notes, also known as anchor links.

To link to a heading, add a hash (#) at the end of the link destination, followed by the heading text.

For example, [[Three laws of motion#Second law]].

You can add multiple hash symbols for each subheading.

For example, [[My note#Heading 1#Heading 2]].

Heading links across the vault
Link to a block in a note
A block is a unit of text in your note, for example a paragraph, block quote, or even a list item.

You can link to a block by adding #^ at the end of your link destination followed by a unique block identifier, for example, [[2023-01-01#^37066d]].

Fortunately, you don't need to know the identifier. When you type the caret (^), you can select the block from a list of suggestions to insert the right identifier.

You can also create human-readable block identifiers by adding a blank space followed by the identifier, for example ^quote-of-the-day, at the end of a block:

"You do not rise to the level of your goals. You fall to the level of your systems." by James Clear ^quote-of-the-day
Now you can instead link to the block by typing [[2023-01-01#^quote-of-the-day]].

Block identifiers can only consist of Latin letters, numbers, and dashes.

Block links across the vault
Interoperability
Block references are specific to Obsidian and not part of the standard Markdown format. Links containing block references won't work outside of Obsidian.

Change the link display text
By default, Obsidian will show the link text, or the alias if you opt to link to an alias. You have the option to modify the text used for displaying a link. This feature comes in handy when you prefer to incorporate a link into a sentence without explicitly using the file name.

Wikilink format:

You can use the vertical bar (|) to change the text used to display a link.

For example, [[Internal links|custom display text]] appears as custom display text.

Markdown format:

Enter the display text between the square brackets ([]).

For example, [custom display text](Internal%20links.md) appears as custom display text.

Preview a linked file
Note
To preview linked files, you first need to enable Page preview.

To preview a linked file, press Ctrl (or Cmd on macOS) while hovering the cursor over the link. A preview of the file content appears next to the cursor.

LINKS TO THIS PAGE
Advanced formatting syntax
Aliases
Basic formatting syntax
Callouts
Embed files
Glossary
Graph view
How Obsidian stores data
Obsidian
Obsidian Flavored Markdown
Properties>>




























































[Go to quote](#^quote-of-the-day)
[Go to heading](#markdown-header-my-paragraph-title)
[Go to heading](#^some-id)