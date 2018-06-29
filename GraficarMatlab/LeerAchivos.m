%Procedemos a cargar la matriz

cd '/home/huaso/Escritorio/Numericos/Lab2-numericos/Integración/Resultados'
archivos = dir ;

for i = 3 : length(archivos)
    texto = load(archivos(i).name);
end




