.PHONY: clean All

All:
	@echo "----------Building project:[ Imagens - Debug ]----------"
	@"$(MAKE)" -f  "Imagens.mk"
clean:
	@echo "----------Cleaning project:[ Imagens - Debug ]----------"
	@"$(MAKE)" -f  "Imagens.mk" clean
