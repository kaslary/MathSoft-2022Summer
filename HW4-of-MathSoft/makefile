FileName=report

report:
	xelatex $(FileName)
	bibtex $(FileName)
	xelatex $(FileName)
	xelatex $(FileName)

clean:
	rm $(FileName).out 
	rm $(FileName).bbl
	rm $(FileName).aux
	rm $(FileName).log
	rm $(FileName).blg
