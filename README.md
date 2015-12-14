#### vježba 9

Koristeći MFC napravite MDI aplikaciju koja ima dva pogleda na dokument: 
  1.	forma za unos koordinata
  2.	crtanje elipse sa zadanim koordinatama

![frame](/screenshot.jpg?raw=true)

Uputstva:

*	napravite pomoću AppWizard-a MFC aplikaciju:
  *	Application type = "Multiple documents"
  *	"Document/View architecture support" je uključen
  *	View klasa (DlgView) je izvedena iz CFormView 
*	na formu stavite 4 static-a i 4 edit-a
*	u projekt dodajte novu klasu (PaintView) izvedenu iz CView
*	u klasu izvedenu iz CWinApp dodajte (privatni) član tipa CMultiDocTemplate* (npr. paintTmpl)
*	u InitInstance() nakon AddDocTemplate()napravite drugi template (koji koristi PaintView):
*	u destruktoru obrišite paintTmpl
*	u Window meni dodajte item za otvaranje novog PaintView, odgovorite na njega u klasi izvedenoj iz CWinApp
*	u dokument klasu dodajte (public) član tipa CRect (npr. rc)
*	u DlgView napravite DDX edit kontrola na direktno na članove dokumentovog CRect
*	u DlgView na EN_KILLFOCUS promijenite podatke dokumenta (UpdateData(true)) i notificirajte ostale prozore o promjeni  (UpdateAllViews)
*	u DlgView na OnUpdate() podatke iz dokumenta postavite u kontrole - UpdateData(false)
*	u PaintView na OnUpdate() forsirajte iscrtavanje prozora - Invalidate()
*	u PaintView na OnDraw() nacrtajte elipsu veličine dokumentovog CRect-a
 
