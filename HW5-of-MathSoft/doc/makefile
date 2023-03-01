FileName=main

report:
	xelatex $(FileName)
	bibtex $(FileName)
	xelatex $(FileName)
	xelatex $(FileName)

clean:
	rm $(FileName).out 
	rm $(FileName).aux
	rm $(FileName).blg	
	rm $(FileName).log
	rm $(FileName).bbl