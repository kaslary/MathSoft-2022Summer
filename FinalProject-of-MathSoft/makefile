FileName=report

report: report.tex

report.tex:
	cd ./doc/report && xelatex $(FileName).tex
	cd ./doc/report && bibtex $(FileName).aux
	cd ./doc/report && xelatex $(FileName).tex
	cd ./doc/report && xelatex $(FileName).tex
	cd ./doc/report && mv $(FileName).pdf ../..
	cd ./doc/report && rm $(FileName).out 
	cd ./doc/report && rm $(FileName).aux
	cd ./doc/report && rm $(FileName).blg	
	cd ./doc/report && rm $(FileName).log
	cd ./doc/report && rm $(FileName).bbl

slide: slide.tex

slide.tex:
	cd ./doc/slide && xelatex slide.tex
	cd ./doc/slide && xelatex slide.tex
	cd ./doc/slide && bibtex slide.aux
	cd ./doc/slide && xelatex slide.tex
	cd ./doc/slide && xelatex slide.tex
	cd ./doc/slide && mv slide.pdf ../..
	cd ./doc/slide && rm slide.aux
	cd ./doc/slide && rm slide.log
	cd ./doc/slide && rm slide.nav
	cd ./doc/slide && rm slide.out
	cd ./doc/slide && rm slide.snm
	cd ./doc/slide && rm slide.toc
	cd ./doc/slide && rm slide.vrb
	cd ./doc/slide && rm slide.bbl
	cd ./doc/slide && rm slide.blg
	
	