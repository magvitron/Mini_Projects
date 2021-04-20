function annotationsEcg = readAnnotations(Name)

annotationName = strcat(Name, '.txt');
fid = fopen(annotationName, 'rt');
annotationsEcg = textscan(fid, '%d:%f %d %*c %*d %*d %*d %s', 'HeaderLines', 1, 'CollectOutput', 1);
fclose(fid);

end
